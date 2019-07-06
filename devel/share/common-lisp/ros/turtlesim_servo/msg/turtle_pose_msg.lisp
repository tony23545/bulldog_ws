; Auto-generated. Do not edit!


(cl:in-package turtlesim_servo-msg)


;//! \htmlinclude turtle_pose_msg.msg.html

(cl:defclass <turtle_pose_msg> (roslisp-msg-protocol:ros-message)
  ((turtle_pose_x
    :reader turtle_pose_x
    :initarg :turtle_pose_x
    :type cl:float
    :initform 0.0)
   (turtle_pose_y
    :reader turtle_pose_y
    :initarg :turtle_pose_y
    :type cl:float
    :initform 0.0)
   (turtle_angle
    :reader turtle_angle
    :initarg :turtle_angle
    :type cl:float
    :initform 0.0))
)

(cl:defclass turtle_pose_msg (<turtle_pose_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <turtle_pose_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'turtle_pose_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlesim_servo-msg:<turtle_pose_msg> is deprecated: use turtlesim_servo-msg:turtle_pose_msg instead.")))

(cl:ensure-generic-function 'turtle_pose_x-val :lambda-list '(m))
(cl:defmethod turtle_pose_x-val ((m <turtle_pose_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlesim_servo-msg:turtle_pose_x-val is deprecated.  Use turtlesim_servo-msg:turtle_pose_x instead.")
  (turtle_pose_x m))

(cl:ensure-generic-function 'turtle_pose_y-val :lambda-list '(m))
(cl:defmethod turtle_pose_y-val ((m <turtle_pose_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlesim_servo-msg:turtle_pose_y-val is deprecated.  Use turtlesim_servo-msg:turtle_pose_y instead.")
  (turtle_pose_y m))

(cl:ensure-generic-function 'turtle_angle-val :lambda-list '(m))
(cl:defmethod turtle_angle-val ((m <turtle_pose_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlesim_servo-msg:turtle_angle-val is deprecated.  Use turtlesim_servo-msg:turtle_angle instead.")
  (turtle_angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <turtle_pose_msg>) ostream)
  "Serializes a message object of type '<turtle_pose_msg>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'turtle_pose_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'turtle_pose_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'turtle_angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <turtle_pose_msg>) istream)
  "Deserializes a message object of type '<turtle_pose_msg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'turtle_pose_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'turtle_pose_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'turtle_angle) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<turtle_pose_msg>)))
  "Returns string type for a message object of type '<turtle_pose_msg>"
  "turtlesim_servo/turtle_pose_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'turtle_pose_msg)))
  "Returns string type for a message object of type 'turtle_pose_msg"
  "turtlesim_servo/turtle_pose_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<turtle_pose_msg>)))
  "Returns md5sum for a message object of type '<turtle_pose_msg>"
  "81f7be54382f129dc66db0841b93073e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'turtle_pose_msg)))
  "Returns md5sum for a message object of type 'turtle_pose_msg"
  "81f7be54382f129dc66db0841b93073e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<turtle_pose_msg>)))
  "Returns full string definition for message of type '<turtle_pose_msg>"
  (cl:format cl:nil "float32 turtle_pose_x~%float32 turtle_pose_y~%float32 turtle_angle~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'turtle_pose_msg)))
  "Returns full string definition for message of type 'turtle_pose_msg"
  (cl:format cl:nil "float32 turtle_pose_x~%float32 turtle_pose_y~%float32 turtle_angle~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <turtle_pose_msg>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <turtle_pose_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'turtle_pose_msg
    (cl:cons ':turtle_pose_x (turtle_pose_x msg))
    (cl:cons ':turtle_pose_y (turtle_pose_y msg))
    (cl:cons ':turtle_angle (turtle_angle msg))
))
