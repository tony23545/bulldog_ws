; Auto-generated. Do not edit!


(cl:in-package turtlesim_servo-msg)


;//! \htmlinclude camera_pose_msg.msg.html

(cl:defclass <camera_pose_msg> (roslisp-msg-protocol:ros-message)
  ((cam_pos_x
    :reader cam_pos_x
    :initarg :cam_pos_x
    :type cl:float
    :initform 0.0)
   (cam_pos_y
    :reader cam_pos_y
    :initarg :cam_pos_y
    :type cl:float
    :initform 0.0))
)

(cl:defclass camera_pose_msg (<camera_pose_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <camera_pose_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'camera_pose_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlesim_servo-msg:<camera_pose_msg> is deprecated: use turtlesim_servo-msg:camera_pose_msg instead.")))

(cl:ensure-generic-function 'cam_pos_x-val :lambda-list '(m))
(cl:defmethod cam_pos_x-val ((m <camera_pose_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlesim_servo-msg:cam_pos_x-val is deprecated.  Use turtlesim_servo-msg:cam_pos_x instead.")
  (cam_pos_x m))

(cl:ensure-generic-function 'cam_pos_y-val :lambda-list '(m))
(cl:defmethod cam_pos_y-val ((m <camera_pose_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlesim_servo-msg:cam_pos_y-val is deprecated.  Use turtlesim_servo-msg:cam_pos_y instead.")
  (cam_pos_y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <camera_pose_msg>) ostream)
  "Serializes a message object of type '<camera_pose_msg>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'cam_pos_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'cam_pos_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <camera_pose_msg>) istream)
  "Deserializes a message object of type '<camera_pose_msg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'cam_pos_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'cam_pos_y) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<camera_pose_msg>)))
  "Returns string type for a message object of type '<camera_pose_msg>"
  "turtlesim_servo/camera_pose_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'camera_pose_msg)))
  "Returns string type for a message object of type 'camera_pose_msg"
  "turtlesim_servo/camera_pose_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<camera_pose_msg>)))
  "Returns md5sum for a message object of type '<camera_pose_msg>"
  "c56fa0c1ba3edbf6476d0b35d0b2030c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'camera_pose_msg)))
  "Returns md5sum for a message object of type 'camera_pose_msg"
  "c56fa0c1ba3edbf6476d0b35d0b2030c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<camera_pose_msg>)))
  "Returns full string definition for message of type '<camera_pose_msg>"
  (cl:format cl:nil "float32 cam_pos_x~%float32 cam_pos_y~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'camera_pose_msg)))
  "Returns full string definition for message of type 'camera_pose_msg"
  (cl:format cl:nil "float32 cam_pos_x~%float32 cam_pos_y~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <camera_pose_msg>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <camera_pose_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'camera_pose_msg
    (cl:cons ':cam_pos_x (cam_pos_x msg))
    (cl:cons ':cam_pos_y (cam_pos_y msg))
))
