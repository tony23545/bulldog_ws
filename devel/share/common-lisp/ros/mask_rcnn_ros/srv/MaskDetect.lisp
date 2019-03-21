; Auto-generated. Do not edit!


(cl:in-package mask_rcnn_ros-srv)


;//! \htmlinclude MaskDetect-request.msg.html

(cl:defclass <MaskDetect-request> (roslisp-msg-protocol:ros-message)
  ((input_image
    :reader input_image
    :initarg :input_image
    :type sensor_msgs-msg:Image
    :initform (cl:make-instance 'sensor_msgs-msg:Image)))
)

(cl:defclass MaskDetect-request (<MaskDetect-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MaskDetect-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MaskDetect-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name mask_rcnn_ros-srv:<MaskDetect-request> is deprecated: use mask_rcnn_ros-srv:MaskDetect-request instead.")))

(cl:ensure-generic-function 'input_image-val :lambda-list '(m))
(cl:defmethod input_image-val ((m <MaskDetect-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mask_rcnn_ros-srv:input_image-val is deprecated.  Use mask_rcnn_ros-srv:input_image instead.")
  (input_image m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MaskDetect-request>) ostream)
  "Serializes a message object of type '<MaskDetect-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'input_image) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MaskDetect-request>) istream)
  "Deserializes a message object of type '<MaskDetect-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'input_image) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MaskDetect-request>)))
  "Returns string type for a service object of type '<MaskDetect-request>"
  "mask_rcnn_ros/MaskDetectRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MaskDetect-request)))
  "Returns string type for a service object of type 'MaskDetect-request"
  "mask_rcnn_ros/MaskDetectRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MaskDetect-request>)))
  "Returns md5sum for a message object of type '<MaskDetect-request>"
  "9a233395163012232dc528a739587d54")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MaskDetect-request)))
  "Returns md5sum for a message object of type 'MaskDetect-request"
  "9a233395163012232dc528a739587d54")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MaskDetect-request>)))
  "Returns full string definition for message of type '<MaskDetect-request>"
  (cl:format cl:nil "sensor_msgs/Image input_image~%~%================================================================================~%MSG: sensor_msgs/Image~%# This message contains an uncompressed image~%# (0, 0) is at top-left corner of image~%#~%~%Header header        # Header timestamp should be acquisition time of image~%                     # Header frame_id should be optical frame of camera~%                     # origin of frame should be optical center of cameara~%                     # +x should point to the right in the image~%                     # +y should point down in the image~%                     # +z should point into to plane of the image~%                     # If the frame_id here and the frame_id of the CameraInfo~%                     # message associated with the image conflict~%                     # the behavior is undefined~%~%uint32 height         # image height, that is, number of rows~%uint32 width          # image width, that is, number of columns~%~%# The legal values for encoding are in file src/image_encodings.cpp~%# If you want to standardize a new string format, join~%# ros-users@lists.sourceforge.net and send an email proposing a new encoding.~%~%string encoding       # Encoding of pixels -- channel meaning, ordering, size~%                      # taken from the list of strings in include/sensor_msgs/image_encodings.h~%~%uint8 is_bigendian    # is this data bigendian?~%uint32 step           # Full row length in bytes~%uint8[] data          # actual matrix data, size is (step * rows)~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MaskDetect-request)))
  "Returns full string definition for message of type 'MaskDetect-request"
  (cl:format cl:nil "sensor_msgs/Image input_image~%~%================================================================================~%MSG: sensor_msgs/Image~%# This message contains an uncompressed image~%# (0, 0) is at top-left corner of image~%#~%~%Header header        # Header timestamp should be acquisition time of image~%                     # Header frame_id should be optical frame of camera~%                     # origin of frame should be optical center of cameara~%                     # +x should point to the right in the image~%                     # +y should point down in the image~%                     # +z should point into to plane of the image~%                     # If the frame_id here and the frame_id of the CameraInfo~%                     # message associated with the image conflict~%                     # the behavior is undefined~%~%uint32 height         # image height, that is, number of rows~%uint32 width          # image width, that is, number of columns~%~%# The legal values for encoding are in file src/image_encodings.cpp~%# If you want to standardize a new string format, join~%# ros-users@lists.sourceforge.net and send an email proposing a new encoding.~%~%string encoding       # Encoding of pixels -- channel meaning, ordering, size~%                      # taken from the list of strings in include/sensor_msgs/image_encodings.h~%~%uint8 is_bigendian    # is this data bigendian?~%uint32 step           # Full row length in bytes~%uint8[] data          # actual matrix data, size is (step * rows)~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MaskDetect-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'input_image))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MaskDetect-request>))
  "Converts a ROS message object to a list"
  (cl:list 'MaskDetect-request
    (cl:cons ':input_image (input_image msg))
))
;//! \htmlinclude MaskDetect-response.msg.html

(cl:defclass <MaskDetect-response> (roslisp-msg-protocol:ros-message)
  ((indices
    :reader indices
    :initarg :indices
    :type (cl:vector std_msgs-msg:Int64)
   :initform (cl:make-array 0 :element-type 'std_msgs-msg:Int64 :initial-element (cl:make-instance 'std_msgs-msg:Int64))))
)

(cl:defclass MaskDetect-response (<MaskDetect-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MaskDetect-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MaskDetect-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name mask_rcnn_ros-srv:<MaskDetect-response> is deprecated: use mask_rcnn_ros-srv:MaskDetect-response instead.")))

(cl:ensure-generic-function 'indices-val :lambda-list '(m))
(cl:defmethod indices-val ((m <MaskDetect-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mask_rcnn_ros-srv:indices-val is deprecated.  Use mask_rcnn_ros-srv:indices instead.")
  (indices m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MaskDetect-response>) ostream)
  "Serializes a message object of type '<MaskDetect-response>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'indices))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'indices))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MaskDetect-response>) istream)
  "Deserializes a message object of type '<MaskDetect-response>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'indices) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'indices)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'std_msgs-msg:Int64))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MaskDetect-response>)))
  "Returns string type for a service object of type '<MaskDetect-response>"
  "mask_rcnn_ros/MaskDetectResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MaskDetect-response)))
  "Returns string type for a service object of type 'MaskDetect-response"
  "mask_rcnn_ros/MaskDetectResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MaskDetect-response>)))
  "Returns md5sum for a message object of type '<MaskDetect-response>"
  "9a233395163012232dc528a739587d54")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MaskDetect-response)))
  "Returns md5sum for a message object of type 'MaskDetect-response"
  "9a233395163012232dc528a739587d54")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MaskDetect-response>)))
  "Returns full string definition for message of type '<MaskDetect-response>"
  (cl:format cl:nil "std_msgs/Int64[] indices~%~%================================================================================~%MSG: std_msgs/Int64~%int64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MaskDetect-response)))
  "Returns full string definition for message of type 'MaskDetect-response"
  (cl:format cl:nil "std_msgs/Int64[] indices~%~%================================================================================~%MSG: std_msgs/Int64~%int64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MaskDetect-response>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'indices) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MaskDetect-response>))
  "Converts a ROS message object to a list"
  (cl:list 'MaskDetect-response
    (cl:cons ':indices (indices msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'MaskDetect)))
  'MaskDetect-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'MaskDetect)))
  'MaskDetect-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MaskDetect)))
  "Returns string type for a service object of type '<MaskDetect>"
  "mask_rcnn_ros/MaskDetect")