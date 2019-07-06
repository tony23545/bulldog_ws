; Auto-generated. Do not edit!


(cl:in-package turtlesim_servo-msg)


;//! \htmlinclude camera_cmd.msg.html

(cl:defclass <camera_cmd> (roslisp-msg-protocol:ros-message)
  ((dx
    :reader dx
    :initarg :dx
    :type cl:integer
    :initform 0)
   (dy
    :reader dy
    :initarg :dy
    :type cl:integer
    :initform 0))
)

(cl:defclass camera_cmd (<camera_cmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <camera_cmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'camera_cmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlesim_servo-msg:<camera_cmd> is deprecated: use turtlesim_servo-msg:camera_cmd instead.")))

(cl:ensure-generic-function 'dx-val :lambda-list '(m))
(cl:defmethod dx-val ((m <camera_cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlesim_servo-msg:dx-val is deprecated.  Use turtlesim_servo-msg:dx instead.")
  (dx m))

(cl:ensure-generic-function 'dy-val :lambda-list '(m))
(cl:defmethod dy-val ((m <camera_cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlesim_servo-msg:dy-val is deprecated.  Use turtlesim_servo-msg:dy instead.")
  (dy m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <camera_cmd>) ostream)
  "Serializes a message object of type '<camera_cmd>"
  (cl:let* ((signed (cl:slot-value msg 'dx)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'dy)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <camera_cmd>) istream)
  "Deserializes a message object of type '<camera_cmd>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dx) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dy) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<camera_cmd>)))
  "Returns string type for a message object of type '<camera_cmd>"
  "turtlesim_servo/camera_cmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'camera_cmd)))
  "Returns string type for a message object of type 'camera_cmd"
  "turtlesim_servo/camera_cmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<camera_cmd>)))
  "Returns md5sum for a message object of type '<camera_cmd>"
  "7ef4e60c6cfeeb3cc8c318b8e4ff545a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'camera_cmd)))
  "Returns md5sum for a message object of type 'camera_cmd"
  "7ef4e60c6cfeeb3cc8c318b8e4ff545a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<camera_cmd>)))
  "Returns full string definition for message of type '<camera_cmd>"
  (cl:format cl:nil "int64 dx~%int64 dy~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'camera_cmd)))
  "Returns full string definition for message of type 'camera_cmd"
  (cl:format cl:nil "int64 dx~%int64 dy~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <camera_cmd>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <camera_cmd>))
  "Converts a ROS message object to a list"
  (cl:list 'camera_cmd
    (cl:cons ':dx (dx msg))
    (cl:cons ':dy (dy msg))
))
