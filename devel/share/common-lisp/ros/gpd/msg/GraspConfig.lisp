; Auto-generated. Do not edit!


(cl:in-package gpd-msg)


;//! \htmlinclude GraspConfig.msg.html

(cl:defclass <GraspConfig> (roslisp-msg-protocol:ros-message)
  ((bottom
    :reader bottom
    :initarg :bottom
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (top
    :reader top
    :initarg :top
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (surface
    :reader surface
    :initarg :surface
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (approach
    :reader approach
    :initarg :approach
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (binormal
    :reader binormal
    :initarg :binormal
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (axis
    :reader axis
    :initarg :axis
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (sample
    :reader sample
    :initarg :sample
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (width
    :reader width
    :initarg :width
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (score
    :reader score
    :initarg :score
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32)))
)

(cl:defclass GraspConfig (<GraspConfig>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GraspConfig>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GraspConfig)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name gpd-msg:<GraspConfig> is deprecated: use gpd-msg:GraspConfig instead.")))

(cl:ensure-generic-function 'bottom-val :lambda-list '(m))
(cl:defmethod bottom-val ((m <GraspConfig>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gpd-msg:bottom-val is deprecated.  Use gpd-msg:bottom instead.")
  (bottom m))

(cl:ensure-generic-function 'top-val :lambda-list '(m))
(cl:defmethod top-val ((m <GraspConfig>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gpd-msg:top-val is deprecated.  Use gpd-msg:top instead.")
  (top m))

(cl:ensure-generic-function 'surface-val :lambda-list '(m))
(cl:defmethod surface-val ((m <GraspConfig>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gpd-msg:surface-val is deprecated.  Use gpd-msg:surface instead.")
  (surface m))

(cl:ensure-generic-function 'approach-val :lambda-list '(m))
(cl:defmethod approach-val ((m <GraspConfig>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gpd-msg:approach-val is deprecated.  Use gpd-msg:approach instead.")
  (approach m))

(cl:ensure-generic-function 'binormal-val :lambda-list '(m))
(cl:defmethod binormal-val ((m <GraspConfig>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gpd-msg:binormal-val is deprecated.  Use gpd-msg:binormal instead.")
  (binormal m))

(cl:ensure-generic-function 'axis-val :lambda-list '(m))
(cl:defmethod axis-val ((m <GraspConfig>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gpd-msg:axis-val is deprecated.  Use gpd-msg:axis instead.")
  (axis m))

(cl:ensure-generic-function 'sample-val :lambda-list '(m))
(cl:defmethod sample-val ((m <GraspConfig>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gpd-msg:sample-val is deprecated.  Use gpd-msg:sample instead.")
  (sample m))

(cl:ensure-generic-function 'width-val :lambda-list '(m))
(cl:defmethod width-val ((m <GraspConfig>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gpd-msg:width-val is deprecated.  Use gpd-msg:width instead.")
  (width m))

(cl:ensure-generic-function 'score-val :lambda-list '(m))
(cl:defmethod score-val ((m <GraspConfig>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gpd-msg:score-val is deprecated.  Use gpd-msg:score instead.")
  (score m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GraspConfig>) ostream)
  "Serializes a message object of type '<GraspConfig>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'bottom) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'top) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'surface) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'approach) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'binormal) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'axis) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'sample) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'width) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'score) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GraspConfig>) istream)
  "Deserializes a message object of type '<GraspConfig>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'bottom) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'top) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'surface) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'approach) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'binormal) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'axis) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'sample) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'width) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'score) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GraspConfig>)))
  "Returns string type for a message object of type '<GraspConfig>"
  "gpd/GraspConfig")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GraspConfig)))
  "Returns string type for a message object of type 'GraspConfig"
  "gpd/GraspConfig")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GraspConfig>)))
  "Returns md5sum for a message object of type '<GraspConfig>"
  "8e6b3c31591d4b0fc202f092dca68301")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GraspConfig)))
  "Returns md5sum for a message object of type 'GraspConfig"
  "8e6b3c31591d4b0fc202f092dca68301")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GraspConfig>)))
  "Returns full string definition for message of type '<GraspConfig>"
  (cl:format cl:nil "# This message describes a 2-finger grasp configuration by its 6-DOF pose, ~%# consisting of a 3-DOF position and 3-DOF orientation, and the opening ~%# width of the robot hand.~%~%# Position~%geometry_msgs/Point bottom # centered bottom/base of the robot hand)~%geometry_msgs/Point top # centered top/fingertip of the robot hand)~%geometry_msgs/Point surface # centered position on object surface~%~%# Orientation represented as three axis (R = [approach binormal axis])~%geometry_msgs/Vector3 approach # The grasp approach direction~%geometry_msgs/Vector3 binormal # The binormal~%geometry_msgs/Vector3 axis # The hand axis~%~%geometry_msgs/Point sample # Point at which the grasp was found~%~%std_msgs/Float32 width # Required aperture (opening width) of the robot hand ~%~%std_msgs/Float32 score # Score assigned to the grasp by the classifier~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GraspConfig)))
  "Returns full string definition for message of type 'GraspConfig"
  (cl:format cl:nil "# This message describes a 2-finger grasp configuration by its 6-DOF pose, ~%# consisting of a 3-DOF position and 3-DOF orientation, and the opening ~%# width of the robot hand.~%~%# Position~%geometry_msgs/Point bottom # centered bottom/base of the robot hand)~%geometry_msgs/Point top # centered top/fingertip of the robot hand)~%geometry_msgs/Point surface # centered position on object surface~%~%# Orientation represented as three axis (R = [approach binormal axis])~%geometry_msgs/Vector3 approach # The grasp approach direction~%geometry_msgs/Vector3 binormal # The binormal~%geometry_msgs/Vector3 axis # The hand axis~%~%geometry_msgs/Point sample # Point at which the grasp was found~%~%std_msgs/Float32 width # Required aperture (opening width) of the robot hand ~%~%std_msgs/Float32 score # Score assigned to the grasp by the classifier~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GraspConfig>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'bottom))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'top))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'surface))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'approach))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'binormal))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'axis))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'sample))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'width))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'score))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GraspConfig>))
  "Converts a ROS message object to a list"
  (cl:list 'GraspConfig
    (cl:cons ':bottom (bottom msg))
    (cl:cons ':top (top msg))
    (cl:cons ':surface (surface msg))
    (cl:cons ':approach (approach msg))
    (cl:cons ':binormal (binormal msg))
    (cl:cons ':axis (axis msg))
    (cl:cons ':sample (sample msg))
    (cl:cons ':width (width msg))
    (cl:cons ':score (score msg))
))
