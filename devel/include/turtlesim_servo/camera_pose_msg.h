// Generated by gencpp from file turtlesim_servo/camera_pose_msg.msg
// DO NOT EDIT!


#ifndef TURTLESIM_SERVO_MESSAGE_CAMERA_POSE_MSG_H
#define TURTLESIM_SERVO_MESSAGE_CAMERA_POSE_MSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace turtlesim_servo
{
template <class ContainerAllocator>
struct camera_pose_msg_
{
  typedef camera_pose_msg_<ContainerAllocator> Type;

  camera_pose_msg_()
    : cam_pos_x(0.0)
    , cam_pos_y(0.0)  {
    }
  camera_pose_msg_(const ContainerAllocator& _alloc)
    : cam_pos_x(0.0)
    , cam_pos_y(0.0)  {
  (void)_alloc;
    }



   typedef float _cam_pos_x_type;
  _cam_pos_x_type cam_pos_x;

   typedef float _cam_pos_y_type;
  _cam_pos_y_type cam_pos_y;




  typedef boost::shared_ptr< ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> const> ConstPtr;

}; // struct camera_pose_msg_

typedef ::turtlesim_servo::camera_pose_msg_<std::allocator<void> > camera_pose_msg;

typedef boost::shared_ptr< ::turtlesim_servo::camera_pose_msg > camera_pose_msgPtr;
typedef boost::shared_ptr< ::turtlesim_servo::camera_pose_msg const> camera_pose_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace turtlesim_servo

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'turtlesim_servo': ['/home/shengjian/bulldog_ws/src/turtlesim_servo/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c56fa0c1ba3edbf6476d0b35d0b2030c";
  }

  static const char* value(const ::turtlesim_servo::camera_pose_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc56fa0c1ba3edbf6ULL;
  static const uint64_t static_value2 = 0x476d0b35d0b2030cULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtlesim_servo/camera_pose_msg";
  }

  static const char* value(const ::turtlesim_servo::camera_pose_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 cam_pos_x\n\
float32 cam_pos_y\n\
";
  }

  static const char* value(const ::turtlesim_servo::camera_pose_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.cam_pos_x);
      stream.next(m.cam_pos_y);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct camera_pose_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlesim_servo::camera_pose_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtlesim_servo::camera_pose_msg_<ContainerAllocator>& v)
  {
    s << indent << "cam_pos_x: ";
    Printer<float>::stream(s, indent + "  ", v.cam_pos_x);
    s << indent << "cam_pos_y: ";
    Printer<float>::stream(s, indent + "  ", v.cam_pos_y);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TURTLESIM_SERVO_MESSAGE_CAMERA_POSE_MSG_H
