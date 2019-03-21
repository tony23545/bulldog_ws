
(cl:in-package :asdf)

(defsystem "robotiq_s_model_articulated_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "SModelRobotInput" :depends-on ("_package_SModelRobotInput"))
    (:file "_package_SModelRobotInput" :depends-on ("_package"))
    (:file "SModelRobotOutput" :depends-on ("_package_SModelRobotOutput"))
    (:file "_package_SModelRobotOutput" :depends-on ("_package"))
  ))