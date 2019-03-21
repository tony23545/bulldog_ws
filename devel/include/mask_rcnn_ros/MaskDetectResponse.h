// Generated by gencpp from file mask_rcnn_ros/MaskDetectResponse.msg
// DO NOT EDIT!


#ifndef MASK_RCNN_ROS_MESSAGE_MASKDETECTRESPONSE_H
#define MASK_RCNN_ROS_MESSAGE_MASKDETECTRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <mask_rcnn_ros/Result.h>

namespace mask_rcnn_ros
{
template <class ContainerAllocator>
struct MaskDetectResponse_
{
  typedef MaskDetectResponse_<ContainerAllocator> Type;

  MaskDetectResponse_()
    : result()  {
    }
  MaskDetectResponse_(const ContainerAllocator& _alloc)
    : result(_alloc)  {
  (void)_alloc;
    }



   typedef  ::mask_rcnn_ros::Result_<ContainerAllocator>  _result_type;
  _result_type result;




  typedef boost::shared_ptr< ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> const> ConstPtr;

}; // struct MaskDetectResponse_

typedef ::mask_rcnn_ros::MaskDetectResponse_<std::allocator<void> > MaskDetectResponse;

typedef boost::shared_ptr< ::mask_rcnn_ros::MaskDetectResponse > MaskDetectResponsePtr;
typedef boost::shared_ptr< ::mask_rcnn_ros::MaskDetectResponse const> MaskDetectResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mask_rcnn_ros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'mask_rcnn_ros': ['/home/shengjian/bulldog_ws/src/mask_rcnn_ros/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "74abec6efc3b682522105270e9e7b31b";
  }

  static const char* value(const ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x74abec6efc3b6825ULL;
  static const uint64_t static_value2 = 0x22105270e9e7b31bULL;
};

template<class ContainerAllocator>
struct DataType< ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mask_rcnn_ros/MaskDetectResponse";
  }

  static const char* value(const ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Result result\n\
\n\
================================================================================\n\
MSG: mask_rcnn_ros/Result\n\
std_msgs/Header header\n\
\n\
# Bounding boxes in pixels\n\
sensor_msgs/RegionOfInterest[] boxes\n\
\n\
# Integer class IDs for each bounding box\n\
int32[] class_ids\n\
\n\
# String class IDs for each bouding box\n\
string[] class_names\n\
\n\
# Float probability scores of the class_id\n\
float32[] scores\n\
\n\
# Instance masks as Image\n\
sensor_msgs/Image[] masks\n\
\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: sensor_msgs/RegionOfInterest\n\
# This message is used to specify a region of interest within an image.\n\
#\n\
# When used to specify the ROI setting of the camera when the image was\n\
# taken, the height and width fields should either match the height and\n\
# width fields for the associated image; or height = width = 0\n\
# indicates that the full resolution image was captured.\n\
\n\
uint32 x_offset  # Leftmost pixel of the ROI\n\
                 # (0 if the ROI includes the left edge of the image)\n\
uint32 y_offset  # Topmost pixel of the ROI\n\
                 # (0 if the ROI includes the top edge of the image)\n\
uint32 height    # Height of ROI\n\
uint32 width     # Width of ROI\n\
\n\
# True if a distinct rectified ROI should be calculated from the \"raw\"\n\
# ROI in this message. Typically this should be False if the full image\n\
# is captured (ROI not used), and True if a subwindow is captured (ROI\n\
# used).\n\
bool do_rectify\n\
\n\
================================================================================\n\
MSG: sensor_msgs/Image\n\
# This message contains an uncompressed image\n\
# (0, 0) is at top-left corner of image\n\
#\n\
\n\
Header header        # Header timestamp should be acquisition time of image\n\
                     # Header frame_id should be optical frame of camera\n\
                     # origin of frame should be optical center of cameara\n\
                     # +x should point to the right in the image\n\
                     # +y should point down in the image\n\
                     # +z should point into to plane of the image\n\
                     # If the frame_id here and the frame_id of the CameraInfo\n\
                     # message associated with the image conflict\n\
                     # the behavior is undefined\n\
\n\
uint32 height         # image height, that is, number of rows\n\
uint32 width          # image width, that is, number of columns\n\
\n\
# The legal values for encoding are in file src/image_encodings.cpp\n\
# If you want to standardize a new string format, join\n\
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.\n\
\n\
string encoding       # Encoding of pixels -- channel meaning, ordering, size\n\
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h\n\
\n\
uint8 is_bigendian    # is this data bigendian?\n\
uint32 step           # Full row length in bytes\n\
uint8[] data          # actual matrix data, size is (step * rows)\n\
";
  }

  static const char* value(const ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MaskDetectResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mask_rcnn_ros::MaskDetectResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    s << std::endl;
    Printer< ::mask_rcnn_ros::Result_<ContainerAllocator> >::stream(s, indent + "  ", v.result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MASK_RCNN_ROS_MESSAGE_MASKDETECTRESPONSE_H
