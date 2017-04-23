
import cv2
import numpy as np
import tflearn
import time
from tflearn.data_preprocessing import ImagePreprocessing
from collections import deque
import operator
import rospy
from r_chatbot.srv import *

from PIL import Image
import sys
class EmotionRecognition:

    def __init__(self):
        self.model = None
        self.longterm_emotion_values = {'Angry': 0.0, 'Disgust': 0.0, 'Fear': 0.0, 'Happy': 0.0, 'Sad': 0.0, 'Surprise': 0.0,
                                   'Neutral': 0.0}
        self.n = 5
        self.start()
        self.emotionreq_server()

    def smooth_emotions(self, prediction):
        emotions = ["Angry", "Disgust", "Fear", "Happy", "Sad", "Surprise", "Neutral"]
        emotion_values = {'Angry': 0.0, 'Disgust': 0.0, 'Fear': 0.0, 'Happy': 0.0, 'Sad': 0.0, 'Surprise': 0.0, 'Neutral': 0.0}
        emotion_probability, emotion_index = max((val, idx) for (idx, val) in enumerate(prediction[0]))
        emotion = emotions[emotion_index]
        #print emotion
        #Append the new emotion and if the maxlength is reached pop the oldest value out
        emotion_queue.appendleft((emotion_probability, emotion))
        run_queue.appendleft((emotion_probability, emotion))

        #Iterate through each emotion in the queue and create an average of the emotions
        for pair in emotion_queue:
            emotion_values[pair[1]] += pair[0]
            self.longterm_emotion_values[pair[1]] += pair[0]
            #Select the current emotion based on the one that has the highest value
        average_emotion = max(emotion_values.iteritems(), key=operator.itemgetter(1))[0]
        return average_emotion

    def process_image(self, roi_gray, img):
        image_scaled = np.array(cv2.resize(roi_gray, (48, 48)), dtype=float)

        #image_processed = image_scaled - np.mean(image_scaled, dtype=float)
        #image_processed = image_processed / np.std(image_scaled, dtype=float)
        image_processed = image_scaled.flatten()
        image_processed = image_processed.reshape([-1, 48, 48, 1])

        #np.savetxt('test_image.csv', image_processed, delimiter=',')
        prediction = self.model.predict(image_processed)
        emotion = self.smooth_emotions(prediction)

        
        #font = cv2.FONT_HERSHEY_SIMPLEX
        #cv2.putText(img, "Emotion: " + emotion, (50, 450), font, 1, (255, 255, 255), 2, cv2.CV_AA)
        #cv2.imshow('img', img)

    def start(self):
        # Real-time preprocessing of the image data
        img_prep = ImagePreprocessing()
        img_prep.add_featurewise_zero_center()
        img_prep.add_featurewise_stdnorm()

        # Real-time data augmentation
        img_aug = tflearn.ImageAugmentation()
        img_aug.add_random_flip_leftright()
        # img_aug.add_random_crop([48, 48], padding=8)

        # Building Residual Network
        net = tflearn.input_data(shape=[None, 48, 48, 1], data_preprocessing=img_prep, data_augmentation=img_aug)
        net = tflearn.conv_2d(net, nb_filter=16, filter_size=3, regularizer='L2', weight_decay=0.0001)
        net = tflearn.residual_block(net, self.n, 16)
        net = tflearn.residual_block(net, 1, 32, downsample=True)
        net = tflearn.residual_block(net, self.n - 1, 32)
        net = tflearn.residual_block(net, 1, 64, downsample=True)
        net = tflearn.residual_block(net, self.n - 1, 64)
        net = tflearn.batch_normalization(net)
        net = tflearn.activation(net, 'relu')
        net = tflearn.global_avg_pool(net)
        # Regression
        net = tflearn.fully_connected(net, 7, activation='softmax')
        mom = tflearn.Momentum(learning_rate=0.1, lr_decay=0.0001, decay_step=32000, staircase=True, momentum=0.9)
        net = tflearn.regression(net, optimizer=mom,
                                 loss='categorical_crossentropy')
        # Training
        self.model = tflearn.DNN(net, checkpoint_path='models/model_resnet_emotion',
                            max_checkpoints=10, tensorboard_verbose=0,
                            clip_gradients=0.)

        self.model.load('current_models/model_resnet_emotion-42000')

    def run(self, devid=0):
        face_cascade = cv2.CascadeClassifier('haar_cascade/haarcascade_frontalface_default.xml')
        cap = cv2.VideoCapture(devid)

        t_end = time.time() + 6
        #Run for the time specified
        face = False
        while time.time() < t_end:
            ret, img = cap.read()
            gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            faces = face_cascade.detectMultiScale(gray, 1.3, 5)
            for (x, y, w, h) in faces:
                cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)
                roi_gray = gray[y:y + h, x:x + w]
                roi_color = img[y:y + h, x:x + w]
                cv2.imwrite('webstream.png', img)
                face = True
                self.process_image(roi_gray, img)
                break
            if face == True:
                break
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break

        cap.release()
        cv2.destroyAllWindows()

    def reset(self):
        emotion_queue = deque(maxlen=10)
        run_queue = deque()

        self.longterm_emotion_values['Angry'] = 0.0
        self.longterm_emotion_values['Disgust'] = 0.0
        self.longterm_emotion_values['Fear'] = 0.0
        self.longterm_emotion_values['Happy'] = 0.0
        self.longterm_emotion_values['Sad'] = 0.0
        self.longterm_emotion_values['Surprise'] = 0.0
        self.longterm_emotion_values['Neutral'] = 0.0

    def get_emotion(self):
        #Iterate through each emotion in the queue and create an average of the emotions
        for pair in run_queue:
            self.longterm_emotion_values[pair[1]] += pair[0]

        #Select the current emotion based on the one that has the highest value
        average_emotion = max(self.longterm_emotion_values.iteritems(), key=operator.itemgetter(1))[0]
        return average_emotion

    def get_avg_emotion(self, req):
        self.run(int(req.devid))
        emotion = self.get_emotion
        self.reset()
        return str(emotion)

    def emotionreq_server(self):
        rospy.init_node('emotionreq_server')
        s1 = rospy.Service('emotionreq', EmotionRecognize, self.get_avg_emotion)
        print "Emotionreq server ready"
        rospy.spin()

# Create emotion queue of last 'x' emotions to smooth the output
emotion_queue = deque(maxlen=10)
run_queue = deque()

emotion = EmotionRecognition()