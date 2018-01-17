
(cl:in-package :asdf)

(defsystem "becker-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "imumsg" :depends-on ("_package_imumsg"))
    (:file "_package_imumsg" :depends-on ("_package"))
    (:file "controlmv" :depends-on ("_package_controlmv"))
    (:file "_package_controlmv" :depends-on ("_package"))
    (:file "wheelpos" :depends-on ("_package_wheelpos"))
    (:file "_package_wheelpos" :depends-on ("_package"))
  ))