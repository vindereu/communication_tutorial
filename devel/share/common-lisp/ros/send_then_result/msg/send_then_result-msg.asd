
(cl:in-package :asdf)

(defsystem "send_then_result-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Arithmetic" :depends-on ("_package_Arithmetic"))
    (:file "_package_Arithmetic" :depends-on ("_package"))
  ))