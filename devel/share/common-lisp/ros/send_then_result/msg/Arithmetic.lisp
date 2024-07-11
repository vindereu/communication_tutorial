; Auto-generated. Do not edit!


(cl:in-package send_then_result-msg)


;//! \htmlinclude Arithmetic.msg.html

(cl:defclass <Arithmetic> (roslisp-msg-protocol:ros-message)
  ((left
    :reader left
    :initarg :left
    :type cl:float
    :initform 0.0)
   (right
    :reader right
    :initarg :right
    :type cl:float
    :initform 0.0)
   (operation
    :reader operation
    :initarg :operation
    :type cl:integer
    :initform 0))
)

(cl:defclass Arithmetic (<Arithmetic>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Arithmetic>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Arithmetic)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name send_then_result-msg:<Arithmetic> is deprecated: use send_then_result-msg:Arithmetic instead.")))

(cl:ensure-generic-function 'left-val :lambda-list '(m))
(cl:defmethod left-val ((m <Arithmetic>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader send_then_result-msg:left-val is deprecated.  Use send_then_result-msg:left instead.")
  (left m))

(cl:ensure-generic-function 'right-val :lambda-list '(m))
(cl:defmethod right-val ((m <Arithmetic>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader send_then_result-msg:right-val is deprecated.  Use send_then_result-msg:right instead.")
  (right m))

(cl:ensure-generic-function 'operation-val :lambda-list '(m))
(cl:defmethod operation-val ((m <Arithmetic>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader send_then_result-msg:operation-val is deprecated.  Use send_then_result-msg:operation instead.")
  (operation m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Arithmetic>) ostream)
  "Serializes a message object of type '<Arithmetic>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'operation)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Arithmetic>) istream)
  "Deserializes a message object of type '<Arithmetic>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'operation)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Arithmetic>)))
  "Returns string type for a message object of type '<Arithmetic>"
  "send_then_result/Arithmetic")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Arithmetic)))
  "Returns string type for a message object of type 'Arithmetic"
  "send_then_result/Arithmetic")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Arithmetic>)))
  "Returns md5sum for a message object of type '<Arithmetic>"
  "baa42b9057bd468f46758350436172b6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Arithmetic)))
  "Returns md5sum for a message object of type 'Arithmetic"
  "baa42b9057bd468f46758350436172b6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Arithmetic>)))
  "Returns full string definition for message of type '<Arithmetic>"
  (cl:format cl:nil "float64 left~%float64 right~%char operation~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Arithmetic)))
  "Returns full string definition for message of type 'Arithmetic"
  (cl:format cl:nil "float64 left~%float64 right~%char operation~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Arithmetic>))
  (cl:+ 0
     8
     8
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Arithmetic>))
  "Converts a ROS message object to a list"
  (cl:list 'Arithmetic
    (cl:cons ':left (left msg))
    (cl:cons ':right (right msg))
    (cl:cons ':operation (operation msg))
))
