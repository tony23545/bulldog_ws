
(cl:in-package :asdf)

(defsystem "turtlesim_servo-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "turtle_cmd" :depends-on ("_package_turtle_cmd"))
    (:file "_package_turtle_cmd" :depends-on ("_package"))
    (:file "camera_cmd" :depends-on ("_package_camera_cmd"))
    (:file "_package_camera_cmd" :depends-on ("_package"))
    (:file "camera_pose_msg" :depends-on ("_package_camera_pose_msg"))
    (:file "_package_camera_pose_msg" :depends-on ("_package"))
    (:file "turtle_pose_msg" :depends-on ("_package_turtle_pose_msg"))
    (:file "_package_turtle_pose_msg" :depends-on ("_package"))
  ))