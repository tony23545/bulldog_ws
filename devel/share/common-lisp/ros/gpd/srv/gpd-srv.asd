
(cl:in-package :asdf)

(defsystem "gpd-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :gpd-msg
               :sensor_msgs-msg
)
  :components ((:file "_package")
    (:file "detect_grasps" :depends-on ("_package_detect_grasps"))
    (:file "_package_detect_grasps" :depends-on ("_package"))
    (:file "pc_transform" :depends-on ("_package_pc_transform"))
    (:file "_package_pc_transform" :depends-on ("_package"))
  ))