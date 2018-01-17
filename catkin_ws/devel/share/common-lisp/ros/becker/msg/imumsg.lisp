; Auto-generated. Do not edit!


(cl:in-package becker-msg)


;//! \htmlinclude imumsg.msg.html

(cl:defclass <imumsg> (roslisp-msg-protocol:ros-message)
  ((imumsg
    :reader imumsg
    :initarg :imumsg
    :type cl:integer
    :initform 0))
)

(cl:defclass imumsg (<imumsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <imumsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'imumsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name becker-msg:<imumsg> is deprecated: use becker-msg:imumsg instead.")))

(cl:ensure-generic-function 'imumsg-val :lambda-list '(m))
(cl:defmethod imumsg-val ((m <imumsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader becker-msg:imumsg-val is deprecated.  Use becker-msg:imumsg instead.")
  (imumsg m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <imumsg>) ostream)
  "Serializes a message object of type '<imumsg>"
  (cl:let* ((signed (cl:slot-value msg 'imumsg)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <imumsg>) istream)
  "Deserializes a message object of type '<imumsg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'imumsg) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<imumsg>)))
  "Returns string type for a message object of type '<imumsg>"
  "becker/imumsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'imumsg)))
  "Returns string type for a message object of type 'imumsg"
  "becker/imumsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<imumsg>)))
  "Returns md5sum for a message object of type '<imumsg>"
  "9db9cbcb4534dd931b602a8e2177c412")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'imumsg)))
  "Returns md5sum for a message object of type 'imumsg"
  "9db9cbcb4534dd931b602a8e2177c412")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<imumsg>)))
  "Returns full string definition for message of type '<imumsg>"
  (cl:format cl:nil "int64 imumsg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'imumsg)))
  "Returns full string definition for message of type 'imumsg"
  (cl:format cl:nil "int64 imumsg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <imumsg>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <imumsg>))
  "Converts a ROS message object to a list"
  (cl:list 'imumsg
    (cl:cons ':imumsg (imumsg msg))
))
