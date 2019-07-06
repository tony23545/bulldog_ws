; Auto-generated. Do not edit!


(cl:in-package robotiq_force_torque_sensor-srv)


;//! \htmlinclude sensor_accessor-request.msg.html

(cl:defclass <sensor_accessor-request> (roslisp-msg-protocol:ros-message)
  ((command
    :reader command
    :initarg :command
    :type cl:string
    :initform ""))
)

(cl:defclass sensor_accessor-request (<sensor_accessor-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <sensor_accessor-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'sensor_accessor-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robotiq_force_torque_sensor-srv:<sensor_accessor-request> is deprecated: use robotiq_force_torque_sensor-srv:sensor_accessor-request instead.")))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <sensor_accessor-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotiq_force_torque_sensor-srv:command-val is deprecated.  Use robotiq_force_torque_sensor-srv:command instead.")
  (command m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <sensor_accessor-request>) ostream)
  "Serializes a message object of type '<sensor_accessor-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'command))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'command))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <sensor_accessor-request>) istream)
  "Deserializes a message object of type '<sensor_accessor-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'command) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'command) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<sensor_accessor-request>)))
  "Returns string type for a service object of type '<sensor_accessor-request>"
  "robotiq_force_torque_sensor/sensor_accessorRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'sensor_accessor-request)))
  "Returns string type for a service object of type 'sensor_accessor-request"
  "robotiq_force_torque_sensor/sensor_accessorRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<sensor_accessor-request>)))
  "Returns md5sum for a message object of type '<sensor_accessor-request>"
  "3432968d93676935641d2adbeeedf719")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'sensor_accessor-request)))
  "Returns md5sum for a message object of type 'sensor_accessor-request"
  "3432968d93676935641d2adbeeedf719")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<sensor_accessor-request>)))
  "Returns full string definition for message of type '<sensor_accessor-request>"
  (cl:format cl:nil "string command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'sensor_accessor-request)))
  "Returns full string definition for message of type 'sensor_accessor-request"
  (cl:format cl:nil "string command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <sensor_accessor-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'command))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <sensor_accessor-request>))
  "Converts a ROS message object to a list"
  (cl:list 'sensor_accessor-request
    (cl:cons ':command (command msg))
))
;//! \htmlinclude sensor_accessor-response.msg.html

(cl:defclass <sensor_accessor-response> (roslisp-msg-protocol:ros-message)
  ((res
    :reader res
    :initarg :res
    :type cl:string
    :initform ""))
)

(cl:defclass sensor_accessor-response (<sensor_accessor-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <sensor_accessor-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'sensor_accessor-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robotiq_force_torque_sensor-srv:<sensor_accessor-response> is deprecated: use robotiq_force_torque_sensor-srv:sensor_accessor-response instead.")))

(cl:ensure-generic-function 'res-val :lambda-list '(m))
(cl:defmethod res-val ((m <sensor_accessor-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotiq_force_torque_sensor-srv:res-val is deprecated.  Use robotiq_force_torque_sensor-srv:res instead.")
  (res m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <sensor_accessor-response>) ostream)
  "Serializes a message object of type '<sensor_accessor-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'res))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'res))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <sensor_accessor-response>) istream)
  "Deserializes a message object of type '<sensor_accessor-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'res) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'res) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<sensor_accessor-response>)))
  "Returns string type for a service object of type '<sensor_accessor-response>"
  "robotiq_force_torque_sensor/sensor_accessorResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'sensor_accessor-response)))
  "Returns string type for a service object of type 'sensor_accessor-response"
  "robotiq_force_torque_sensor/sensor_accessorResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<sensor_accessor-response>)))
  "Returns md5sum for a message object of type '<sensor_accessor-response>"
  "3432968d93676935641d2adbeeedf719")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'sensor_accessor-response)))
  "Returns md5sum for a message object of type 'sensor_accessor-response"
  "3432968d93676935641d2adbeeedf719")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<sensor_accessor-response>)))
  "Returns full string definition for message of type '<sensor_accessor-response>"
  (cl:format cl:nil "string res~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'sensor_accessor-response)))
  "Returns full string definition for message of type 'sensor_accessor-response"
  (cl:format cl:nil "string res~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <sensor_accessor-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'res))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <sensor_accessor-response>))
  "Converts a ROS message object to a list"
  (cl:list 'sensor_accessor-response
    (cl:cons ':res (res msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'sensor_accessor)))
  'sensor_accessor-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'sensor_accessor)))
  'sensor_accessor-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'sensor_accessor)))
  "Returns string type for a service object of type '<sensor_accessor>"
  "robotiq_force_torque_sensor/sensor_accessor")