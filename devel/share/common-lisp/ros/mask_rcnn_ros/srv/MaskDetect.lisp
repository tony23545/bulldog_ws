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
  "1de517f411134622360bbeab63b02eaa")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MaskDetect-request)))
  "Returns md5sum for a message object of type 'MaskDetect-request"
  "1de517f411134622360bbeab63b02eaa")
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
  ((result
    :reader result
    :initarg :result
    :type mask_rcnn_ros-msg:Result
    :initform (cl:make-instance 'mask_rcnn_ros-msg:Result)))
)

(cl:defclass MaskDetect-response (<MaskDetect-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MaskDetect-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MaskDetect-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name mask_rcnn_ros-srv:<MaskDetect-response> is deprecated: use mask_rcnn_ros-srv:MaskDetect-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <MaskDetect-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mask_rcnn_ros-srv:result-val is deprecated.  Use mask_rcnn_ros-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MaskDetect-response>) ostream)
  "Serializes a message object of type '<MaskDetect-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'result) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MaskDetect-response>) istream)
  "Deserializes a message object of type '<MaskDetect-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'result) istream)
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
  "1de517f411134622360bbeab63b02eaa")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MaskDetect-response)))
  "Returns md5sum for a message object of type 'MaskDetect-response"
  "1de517f411134622360bbeab63b02eaa")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MaskDetect-response>)))
  "Returns full string definition for message of type '<MaskDetect-response>"
  (cl:format cl:nil "Result result~%~%================================================================================~%MSG: mask_rcnn_ros/Result~%std_msgs/Header header~%~%# Bounding boxes in pixels~%sensor_msgs/RegionOfInterest[] boxes~%~%# Integer class IDs for each bounding box~%int32[] class_ids~%~%# String class IDs for each bouding box~%string[] class_names~%~%# Float probability scores of the class_id~%float32[] scores~%~%# Instance masks as Image~%sensor_msgs/Image[] masks~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: sensor_msgs/RegionOfInterest~%# This message is used to specify a region of interest within an image.~%#~%# When used to specify the ROI setting of the camera when the image was~%# taken, the height and width fields should either match the height and~%# width fields for the associated image; or height = width = 0~%# indicates that the full resolution image was captured.~%~%uint32 x_offset  # Leftmost pixel of the ROI~%                 # (0 if the ROI includes the left edge of the image)~%uint32 y_offset  # Topmost pixel of the ROI~%                 # (0 if the ROI includes the top edge of the image)~%uint32 height    # Height of ROI~%uint32 width     # Width of ROI~%~%# True if a distinct rectified ROI should be calculated from the \"raw\"~%# ROI in this message. Typically this should be False if the full image~%# is captured (ROI not used), and True if a subwindow is captured (ROI~%# used).~%bool do_rectify~%~%================================================================================~%MSG: sensor_msgs/Image~%# This message contains an uncompressed image~%# (0, 0) is at top-left corner of image~%#~%~%Header header        # Header timestamp should be acquisition time of image~%                     # Header frame_id should be optical frame of camera~%                     # origin of frame should be optical center of cameara~%                     # +x should point to the right in the image~%                     # +y should point down in the image~%                     # +z should point into to plane of the image~%                     # If the frame_id here and the frame_id of the CameraInfo~%                     # message associated with the image conflict~%                     # the behavior is undefined~%~%uint32 height         # image height, that is, number of rows~%uint32 width          # image width, that is, number of columns~%~%# The legal values for encoding are in file src/image_encodings.cpp~%# If you want to standardize a new string format, join~%# ros-users@lists.sourceforge.net and send an email proposing a new encoding.~%~%string encoding       # Encoding of pixels -- channel meaning, ordering, size~%                      # taken from the list of strings in include/sensor_msgs/image_encodings.h~%~%uint8 is_bigendian    # is this data bigendian?~%uint32 step           # Full row length in bytes~%uint8[] data          # actual matrix data, size is (step * rows)~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MaskDetect-response)))
  "Returns full string definition for message of type 'MaskDetect-response"
  (cl:format cl:nil "Result result~%~%================================================================================~%MSG: mask_rcnn_ros/Result~%std_msgs/Header header~%~%# Bounding boxes in pixels~%sensor_msgs/RegionOfInterest[] boxes~%~%# Integer class IDs for each bounding box~%int32[] class_ids~%~%# String class IDs for each bouding box~%string[] class_names~%~%# Float probability scores of the class_id~%float32[] scores~%~%# Instance masks as Image~%sensor_msgs/Image[] masks~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: sensor_msgs/RegionOfInterest~%# This message is used to specify a region of interest within an image.~%#~%# When used to specify the ROI setting of the camera when the image was~%# taken, the height and width fields should either match the height and~%# width fields for the associated image; or height = width = 0~%# indicates that the full resolution image was captured.~%~%uint32 x_offset  # Leftmost pixel of the ROI~%                 # (0 if the ROI includes the left edge of the image)~%uint32 y_offset  # Topmost pixel of the ROI~%                 # (0 if the ROI includes the top edge of the image)~%uint32 height    # Height of ROI~%uint32 width     # Width of ROI~%~%# True if a distinct rectified ROI should be calculated from the \"raw\"~%# ROI in this message. Typically this should be False if the full image~%# is captured (ROI not used), and True if a subwindow is captured (ROI~%# used).~%bool do_rectify~%~%================================================================================~%MSG: sensor_msgs/Image~%# This message contains an uncompressed image~%# (0, 0) is at top-left corner of image~%#~%~%Header header        # Header timestamp should be acquisition time of image~%                     # Header frame_id should be optical frame of camera~%                     # origin of frame should be optical center of cameara~%                     # +x should point to the right in the image~%                     # +y should point down in the image~%                     # +z should point into to plane of the image~%                     # If the frame_id here and the frame_id of the CameraInfo~%                     # message associated with the image conflict~%                     # the behavior is undefined~%~%uint32 height         # image height, that is, number of rows~%uint32 width          # image width, that is, number of columns~%~%# The legal values for encoding are in file src/image_encodings.cpp~%# If you want to standardize a new string format, join~%# ros-users@lists.sourceforge.net and send an email proposing a new encoding.~%~%string encoding       # Encoding of pixels -- channel meaning, ordering, size~%                      # taken from the list of strings in include/sensor_msgs/image_encodings.h~%~%uint8 is_bigendian    # is this data bigendian?~%uint32 step           # Full row length in bytes~%uint8[] data          # actual matrix data, size is (step * rows)~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MaskDetect-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'result))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MaskDetect-response>))
  "Converts a ROS message object to a list"
  (cl:list 'MaskDetect-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'MaskDetect)))
  'MaskDetect-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'MaskDetect)))
  'MaskDetect-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MaskDetect)))
  "Returns string type for a service object of type '<MaskDetect>"
  "mask_rcnn_ros/MaskDetect")