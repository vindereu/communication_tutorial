;; Auto-generated. Do not edit!


(when (boundp 'send_then_result::Arithmetic)
  (if (not (find-package "SEND_THEN_RESULT"))
    (make-package "SEND_THEN_RESULT"))
  (shadow 'Arithmetic (find-package "SEND_THEN_RESULT")))
(unless (find-package "SEND_THEN_RESULT::ARITHMETIC")
  (make-package "SEND_THEN_RESULT::ARITHMETIC"))

(in-package "ROS")
;;//! \htmlinclude Arithmetic.msg.html


(defclass send_then_result::Arithmetic
  :super ros::object
  :slots (_left _right _operation ))

(defmethod send_then_result::Arithmetic
  (:init
   (&key
    ((:left __left) 0.0)
    ((:right __right) 0.0)
    ((:operation __operation) 0)
    )
   (send-super :init)
   (setq _left (float __left))
   (setq _right (float __right))
   (setq _operation (round __operation))
   self)
  (:left
   (&optional __left)
   (if __left (setq _left __left)) _left)
  (:right
   (&optional __right)
   (if __right (setq _right __right)) _right)
  (:operation
   (&optional __operation)
   (if __operation (setq _operation __operation)) _operation)
  (:serialization-length
   ()
   (+
    ;; float64 _left
    8
    ;; float64 _right
    8
    ;; char _operation
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _left
       (sys::poke _left (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right
       (sys::poke _right (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; char _operation
       (write-byte _operation s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _left
     (setq _left (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right
     (setq _right (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; char _operation
     (setq _operation (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get send_then_result::Arithmetic :md5sum-) "baa42b9057bd468f46758350436172b6")
(setf (get send_then_result::Arithmetic :datatype-) "send_then_result/Arithmetic")
(setf (get send_then_result::Arithmetic :definition-)
      "float64 left
float64 right
char operation

")



(provide :send_then_result/Arithmetic "baa42b9057bd468f46758350436172b6")


