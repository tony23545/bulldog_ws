; Auto-generated. Do not edit!


(cl:in-package turtlesim_servo-msg)


;//! \htmlinclude turtle_cmd.msg.html

(cl:defclass <turtle_cmd> (roslisp-msg-protocol:ros-message)
  ((acc
    :reader acc
    :initarg :acc
    :type cl:float
    :initform 0.0)
   (d_angle
    :reader d_angle
    :initarg :d_angle
    :type cl:float
    :initform 0.0))
)

(cl:defclass turtle_cmd (<turtle_cmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <turtle_cmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'turtle_cmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlesim_servo-msg:<turtle_cmd> is deprecated: use turtlesim_servo-msg:turtle_cmd instead.")))

(cl:ensure-generic-function 'acc-val :lambda-list '(m))
(cl:defmethod acc-val ((m <turtle_cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlesim_servo-msg:acc-val is deprecated.  Use turtlesim_servo-msg:acc instead.")
  (acc m))

(cl:ensure-generic-function 'd_angle-val :lambda-list '(m))
(cl:defmethod d_angle-val ((m <turtle_cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlesim_servo-msg:d_angle-val is deprecated.  Use turtlesim_servo-msg:d_angle instead.")
  (d_angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <turtle_cmd>) ostream)
  "Serializes a message object of type '<turtle_cmd>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'acc))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'd_angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <turtle_cmd>) istream)
  "Deserializes a message object of type '<turtle_cmd>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'acc) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'd_angle) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<turtle_cmd>)))
  "Returns string type for a message object of type '<turtle_cmd>"
  "turtlesim_servo/turtle_cmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'turtle_cmd)))
  "Returns string type for a message object of type 'turtle_cmd"
  "turtlesim_servo/turtle_cmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<turtle_cmd>)))
  "Returns md5sum for a message object of type '<turtle_cmd>"
  "b6c9aabef2c9a5b6c2f5599cd4f73216")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'turtle_cmd)))
  "Returns md5sum for a message object of type 'turtle_cmd"
  "b6c9aabef2c9a5b6c2f5599cd4f73216")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<turtle_cmd>)))
  "Returns full string definition for message of type '<turtle_cmd>"
  (cl:format cl:nil "float32 acc~%float32 d_angle~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'turtle_cmd)))
  "Returns full string definition for message of type 'turtle_cmd"
  (cl:format cl:nil "float32 acc~%float32 d_angle~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <turtle_cmd>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <turtle_cmd>))
  "Converts a ROS message object to a list"
  (cl:list 'turtle_cmd
    (cl:cons ':acc (acc msg))
    (cl:cons ':d_angle (d_angle msg))
))
