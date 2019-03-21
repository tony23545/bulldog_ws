
(cl:in-package :asdf)

(defsystem "mask_rcnn_ros-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :mask_rcnn_ros-msg
               :sensor_msgs-msg
)
  :components ((:file "_package")
    (:file "MaskDetect" :depends-on ("_package_MaskDetect"))
    (:file "_package_MaskDetect" :depends-on ("_package"))
  ))