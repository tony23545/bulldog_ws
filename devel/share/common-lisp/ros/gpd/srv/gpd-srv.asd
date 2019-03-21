
(cl:in-package :asdf)

(defsystem "gpd-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :gpd-msg
)
  :components ((:file "_package")
    (:file "detect_grasps" :depends-on ("_package_detect_grasps"))
    (:file "_package_detect_grasps" :depends-on ("_package"))
  ))