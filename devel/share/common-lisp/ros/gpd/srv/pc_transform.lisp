; Auto-generated. Do not edit!


(cl:in-package gpd-srv)


;//! \htmlinclude pc_transform-request.msg.html

(cl:defclass <pc_transform-request> (roslisp-msg-protocol:ros-message)
  ((in_cloud
    :reader in_cloud
    :initarg :in_cloud
    :type sensor_msgs-msg:PointCloud2
    :initform (cl:make-instance 'sensor_msgs-msg:PointCloud2)))
)

(cl:defclass pc_transform-request (<pc_transform-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pc_transform-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pc_transform-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name gpd-srv:<pc_transform-request> is deprecated: use gpd-srv:pc_transform-request instead.")))

(cl:ensure-generic-function 'in_cloud-val :lambda-list '(m))
(cl:defmethod in_cloud-val ((m <pc_transform-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gpd-srv:in_cloud-val is deprecated.  Use gpd-srv:in_cloud instead.")
  (in_cloud m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pc_transform-request>) ostream)
  "Serializes a message object of type '<pc_transform-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'in_cloud) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pc_transform-request>) istream)
  "Deserializes a message object of type '<pc_transform-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'in_cloud) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pc_transform-request>)))
  "Returns string type for a service object of type '<pc_transform-request>"
  "gpd/pc_transformRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pc_transform-request)))
  "Returns string type for a service object of type 'pc_transform-request"
  "gpd/pc_transformRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pc_transform-request>)))
  "Returns md5sum for a message object of type '<pc_transform-request>"
  "c358e51efa4fc841b3755e5d2015c919")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pc_transform-request)))
  "Returns md5sum for a message object of type 'pc_transform-request"
  "c358e51efa4fc841b3755e5d2015c919")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pc_transform-request>)))
  "Returns full string definition for message of type '<pc_transform-request>"
  (cl:format cl:nil "sensor_msgs/PointCloud2 in_cloud~%~%================================================================================~%MSG: sensor_msgs/PointCloud2~%# This message holds a collection of N-dimensional points, which may~%# contain additional information such as normals, intensity, etc. The~%# point data is stored as a binary blob, its layout described by the~%# contents of the \"fields\" array.~%~%# The point cloud data may be organized 2d (image-like) or 1d~%# (unordered). Point clouds organized as 2d images may be produced by~%# camera depth sensors such as stereo or time-of-flight.~%~%# Time of sensor data acquisition, and the coordinate frame ID (for 3d~%# points).~%Header header~%~%# 2D structure of the point cloud. If the cloud is unordered, height is~%# 1 and width is the length of the point cloud.~%uint32 height~%uint32 width~%~%# Describes the channels and their layout in the binary data blob.~%PointField[] fields~%~%bool    is_bigendian # Is this data bigendian?~%uint32  point_step   # Length of a point in bytes~%uint32  row_step     # Length of a row in bytes~%uint8[] data         # Actual point data, size is (row_step*height)~%~%bool is_dense        # True if there are no invalid points~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: sensor_msgs/PointField~%# This message holds the description of one point entry in the~%# PointCloud2 message format.~%uint8 INT8    = 1~%uint8 UINT8   = 2~%uint8 INT16   = 3~%uint8 UINT16  = 4~%uint8 INT32   = 5~%uint8 UINT32  = 6~%uint8 FLOAT32 = 7~%uint8 FLOAT64 = 8~%~%string name      # Name of field~%uint32 offset    # Offset from start of point struct~%uint8  datatype  # Datatype enumeration, see above~%uint32 count     # How many elements in the field~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pc_transform-request)))
  "Returns full string definition for message of type 'pc_transform-request"
  (cl:format cl:nil "sensor_msgs/PointCloud2 in_cloud~%~%================================================================================~%MSG: sensor_msgs/PointCloud2~%# This message holds a collection of N-dimensional points, which may~%# contain additional information such as normals, intensity, etc. The~%# point data is stored as a binary blob, its layout described by the~%# contents of the \"fields\" array.~%~%# The point cloud data may be organized 2d (image-like) or 1d~%# (unordered). Point clouds organized as 2d images may be produced by~%# camera depth sensors such as stereo or time-of-flight.~%~%# Time of sensor data acquisition, and the coordinate frame ID (for 3d~%# points).~%Header header~%~%# 2D structure of the point cloud. If the cloud is unordered, height is~%# 1 and width is the length of the point cloud.~%uint32 height~%uint32 width~%~%# Describes the channels and their layout in the binary data blob.~%PointField[] fields~%~%bool    is_bigendian # Is this data bigendian?~%uint32  point_step   # Length of a point in bytes~%uint32  row_step     # Length of a row in bytes~%uint8[] data         # Actual point data, size is (row_step*height)~%~%bool is_dense        # True if there are no invalid points~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: sensor_msgs/PointField~%# This message holds the description of one point entry in the~%# PointCloud2 message format.~%uint8 INT8    = 1~%uint8 UINT8   = 2~%uint8 INT16   = 3~%uint8 UINT16  = 4~%uint8 INT32   = 5~%uint8 UINT32  = 6~%uint8 FLOAT32 = 7~%uint8 FLOAT64 = 8~%~%string name      # Name of field~%uint32 offset    # Offset from start of point struct~%uint8  datatype  # Datatype enumeration, see above~%uint32 count     # How many elements in the field~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pc_transform-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'in_cloud))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pc_transform-request>))
  "Converts a ROS message object to a list"
  (cl:list 'pc_transform-request
    (cl:cons ':in_cloud (in_cloud msg))
))
;//! \htmlinclude pc_transform-response.msg.html

(cl:defclass <pc_transform-response> (roslisp-msg-protocol:ros-message)
  ((out_cloud
    :reader out_cloud
    :initarg :out_cloud
    :type sensor_msgs-msg:PointCloud2
    :initform (cl:make-instance 'sensor_msgs-msg:PointCloud2)))
)

(cl:defclass pc_transform-response (<pc_transform-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pc_transform-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pc_transform-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name gpd-srv:<pc_transform-response> is deprecated: use gpd-srv:pc_transform-response instead.")))

(cl:ensure-generic-function 'out_cloud-val :lambda-list '(m))
(cl:defmethod out_cloud-val ((m <pc_transform-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gpd-srv:out_cloud-val is deprecated.  Use gpd-srv:out_cloud instead.")
  (out_cloud m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pc_transform-response>) ostream)
  "Serializes a message object of type '<pc_transform-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'out_cloud) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pc_transform-response>) istream)
  "Deserializes a message object of type '<pc_transform-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'out_cloud) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pc_transform-response>)))
  "Returns string type for a service object of type '<pc_transform-response>"
  "gpd/pc_transformResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pc_transform-response)))
  "Returns string type for a service object of type 'pc_transform-response"
  "gpd/pc_transformResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pc_transform-response>)))
  "Returns md5sum for a message object of type '<pc_transform-response>"
  "c358e51efa4fc841b3755e5d2015c919")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pc_transform-response)))
  "Returns md5sum for a message object of type 'pc_transform-response"
  "c358e51efa4fc841b3755e5d2015c919")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pc_transform-response>)))
  "Returns full string definition for message of type '<pc_transform-response>"
  (cl:format cl:nil "sensor_msgs/PointCloud2 out_cloud~%~%================================================================================~%MSG: sensor_msgs/PointCloud2~%# This message holds a collection of N-dimensional points, which may~%# contain additional information such as normals, intensity, etc. The~%# point data is stored as a binary blob, its layout described by the~%# contents of the \"fields\" array.~%~%# The point cloud data may be organized 2d (image-like) or 1d~%# (unordered). Point clouds organized as 2d images may be produced by~%# camera depth sensors such as stereo or time-of-flight.~%~%# Time of sensor data acquisition, and the coordinate frame ID (for 3d~%# points).~%Header header~%~%# 2D structure of the point cloud. If the cloud is unordered, height is~%# 1 and width is the length of the point cloud.~%uint32 height~%uint32 width~%~%# Describes the channels and their layout in the binary data blob.~%PointField[] fields~%~%bool    is_bigendian # Is this data bigendian?~%uint32  point_step   # Length of a point in bytes~%uint32  row_step     # Length of a row in bytes~%uint8[] data         # Actual point data, size is (row_step*height)~%~%bool is_dense        # True if there are no invalid points~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: sensor_msgs/PointField~%# This message holds the description of one point entry in the~%# PointCloud2 message format.~%uint8 INT8    = 1~%uint8 UINT8   = 2~%uint8 INT16   = 3~%uint8 UINT16  = 4~%uint8 INT32   = 5~%uint8 UINT32  = 6~%uint8 FLOAT32 = 7~%uint8 FLOAT64 = 8~%~%string name      # Name of field~%uint32 offset    # Offset from start of point struct~%uint8  datatype  # Datatype enumeration, see above~%uint32 count     # How many elements in the field~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pc_transform-response)))
  "Returns full string definition for message of type 'pc_transform-response"
  (cl:format cl:nil "sensor_msgs/PointCloud2 out_cloud~%~%================================================================================~%MSG: sensor_msgs/PointCloud2~%# This message holds a collection of N-dimensional points, which may~%# contain additional information such as normals, intensity, etc. The~%# point data is stored as a binary blob, its layout described by the~%# contents of the \"fields\" array.~%~%# The point cloud data may be organized 2d (image-like) or 1d~%# (unordered). Point clouds organized as 2d images may be produced by~%# camera depth sensors such as stereo or time-of-flight.~%~%# Time of sensor data acquisition, and the coordinate frame ID (for 3d~%# points).~%Header header~%~%# 2D structure of the point cloud. If the cloud is unordered, height is~%# 1 and width is the length of the point cloud.~%uint32 height~%uint32 width~%~%# Describes the channels and their layout in the binary data blob.~%PointField[] fields~%~%bool    is_bigendian # Is this data bigendian?~%uint32  point_step   # Length of a point in bytes~%uint32  row_step     # Length of a row in bytes~%uint8[] data         # Actual point data, size is (row_step*height)~%~%bool is_dense        # True if there are no invalid points~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: sensor_msgs/PointField~%# This message holds the description of one point entry in the~%# PointCloud2 message format.~%uint8 INT8    = 1~%uint8 UINT8   = 2~%uint8 INT16   = 3~%uint8 UINT16  = 4~%uint8 INT32   = 5~%uint8 UINT32  = 6~%uint8 FLOAT32 = 7~%uint8 FLOAT64 = 8~%~%string name      # Name of field~%uint32 offset    # Offset from start of point struct~%uint8  datatype  # Datatype enumeration, see above~%uint32 count     # How many elements in the field~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pc_transform-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'out_cloud))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pc_transform-response>))
  "Converts a ROS message object to a list"
  (cl:list 'pc_transform-response
    (cl:cons ':out_cloud (out_cloud msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'pc_transform)))
  'pc_transform-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'pc_transform)))
  'pc_transform-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pc_transform)))
  "Returns string type for a service object of type '<pc_transform>"
  "gpd/pc_transform")