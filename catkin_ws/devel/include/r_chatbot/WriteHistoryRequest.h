// Generated by gencpp from file r_chatbot/WriteHistoryRequest.msg
// DO NOT EDIT!


#ifndef R_CHATBOT_MESSAGE_WRITEHISTORYREQUEST_H
#define R_CHATBOT_MESSAGE_WRITEHISTORYREQUEST_H


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
struct WriteHistoryRequest_
{
  typedef WriteHistoryRequest_<ContainerAllocator> Type;

  WriteHistoryRequest_()
    : username()  {
    }
  WriteHistoryRequest_(const ContainerAllocator& _alloc)
    : username(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _username_type;
  _username_type username;




  typedef boost::shared_ptr< ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> const> ConstPtr;

}; // struct WriteHistoryRequest_

typedef ::r_chatbot::WriteHistoryRequest_<std::allocator<void> > WriteHistoryRequest;

typedef boost::shared_ptr< ::r_chatbot::WriteHistoryRequest > WriteHistoryRequestPtr;
typedef boost::shared_ptr< ::r_chatbot::WriteHistoryRequest const> WriteHistoryRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e6839c60033378e900ba73a23bfa5117";
  }

  static const char* value(const ::r_chatbot::WriteHistoryRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe6839c60033378e9ULL;
  static const uint64_t static_value2 = 0x00ba73a23bfa5117ULL;
};

template<class ContainerAllocator>
struct DataType< ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "r_chatbot/WriteHistoryRequest";
  }

  static const char* value(const ::r_chatbot::WriteHistoryRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string username\n\
\n\
";
  }

  static const char* value(const ::r_chatbot::WriteHistoryRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.username);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct WriteHistoryRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::r_chatbot::WriteHistoryRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::r_chatbot::WriteHistoryRequest_<ContainerAllocator>& v)
  {
    s << indent << "username: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.username);
  }
};

} // namespace message_operations
} // namespace ros

#endif // R_CHATBOT_MESSAGE_WRITEHISTORYREQUEST_H
