// Generated by gencpp from file r_chatbot/ContextResponse.msg
// DO NOT EDIT!


#ifndef R_CHATBOT_MESSAGE_CONTEXTRESPONSE_H
#define R_CHATBOT_MESSAGE_CONTEXTRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace r_chatbot
{
template <class ContainerAllocator>
struct ContextResponse_
{
  typedef ContextResponse_<ContainerAllocator> Type;

  ContextResponse_()
    : response()
    , correlation(0.0)  {
    }
  ContextResponse_(const ContainerAllocator& _alloc)
    : response(_alloc)
    , correlation(0.0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _response_type;
  _response_type response;

   typedef float _correlation_type;
  _correlation_type correlation;




  typedef boost::shared_ptr< ::r_chatbot::ContextResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::r_chatbot::ContextResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ContextResponse_

typedef ::r_chatbot::ContextResponse_<std::allocator<void> > ContextResponse;

typedef boost::shared_ptr< ::r_chatbot::ContextResponse > ContextResponsePtr;
typedef boost::shared_ptr< ::r_chatbot::ContextResponse const> ContextResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::r_chatbot::ContextResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::r_chatbot::ContextResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace r_chatbot

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/media/sf_GitHub/Perception_Robotics/catkin_ws/src/std_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::r_chatbot::ContextResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::r_chatbot::ContextResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::r_chatbot::ContextResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::r_chatbot::ContextResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::r_chatbot::ContextResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::r_chatbot::ContextResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::r_chatbot::ContextResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f41fbe2a049e9d92d10ece8e98c1cee2";
  }

  static const char* value(const ::r_chatbot::ContextResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf41fbe2a049e9d92ULL;
  static const uint64_t static_value2 = 0xd10ece8e98c1cee2ULL;
};

template<class ContainerAllocator>
struct DataType< ::r_chatbot::ContextResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "r_chatbot/ContextResponse";
  }

  static const char* value(const ::r_chatbot::ContextResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::r_chatbot::ContextResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
string response\n\
float32 correlation\n\
";
  }

  static const char* value(const ::r_chatbot::ContextResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::r_chatbot::ContextResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.response);
      stream.next(m.correlation);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ContextResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::r_chatbot::ContextResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::r_chatbot::ContextResponse_<ContainerAllocator>& v)
  {
    s << indent << "response: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.response);
    s << indent << "correlation: ";
    Printer<float>::stream(s, indent + "  ", v.correlation);
  }
};

} // namespace message_operations
} // namespace ros

#endif // R_CHATBOT_MESSAGE_CONTEXTRESPONSE_H