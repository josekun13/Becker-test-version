// Generated by gencpp from file becker/controlmv.msg
// DO NOT EDIT!


#ifndef BECKER_MESSAGE_CONTROLMV_H
#define BECKER_MESSAGE_CONTROLMV_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace becker
{
template <class ContainerAllocator>
struct controlmv_
{
  typedef controlmv_<ContainerAllocator> Type;

  controlmv_()
    : num(0)  {
    }
  controlmv_(const ContainerAllocator& _alloc)
    : num(0)  {
  (void)_alloc;
    }



   typedef int64_t _num_type;
  _num_type num;




  typedef boost::shared_ptr< ::becker::controlmv_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::becker::controlmv_<ContainerAllocator> const> ConstPtr;

}; // struct controlmv_

typedef ::becker::controlmv_<std::allocator<void> > controlmv;

typedef boost::shared_ptr< ::becker::controlmv > controlmvPtr;
typedef boost::shared_ptr< ::becker::controlmv const> controlmvConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::becker::controlmv_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::becker::controlmv_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace becker

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'becker': ['/home/pi/catkin_ws/src/becker/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::becker::controlmv_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::becker::controlmv_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::becker::controlmv_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::becker::controlmv_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::becker::controlmv_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::becker::controlmv_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::becker::controlmv_<ContainerAllocator> >
{
  static const char* value()
  {
    return "57d3c40ec3ac3754af76a83e6e73127a";
  }

  static const char* value(const ::becker::controlmv_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x57d3c40ec3ac3754ULL;
  static const uint64_t static_value2 = 0xaf76a83e6e73127aULL;
};

template<class ContainerAllocator>
struct DataType< ::becker::controlmv_<ContainerAllocator> >
{
  static const char* value()
  {
    return "becker/controlmv";
  }

  static const char* value(const ::becker::controlmv_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::becker::controlmv_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 num\n\
";
  }

  static const char* value(const ::becker::controlmv_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::becker::controlmv_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.num);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct controlmv_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::becker::controlmv_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::becker::controlmv_<ContainerAllocator>& v)
  {
    s << indent << "num: ";
    Printer<int64_t>::stream(s, indent + "  ", v.num);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BECKER_MESSAGE_CONTROLMV_H
