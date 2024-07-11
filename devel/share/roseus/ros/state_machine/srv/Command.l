;; Auto-generated. Do not edit!


(when (boundp 'state_machine::Command)
  (if (not (find-package "STATE_MACHINE"))
    (make-package "STATE_MACHINE"))
  (shadow 'Command (find-package "STATE_MACHINE")))
(unless (find-package "STATE_MACHINE::COMMAND")
  (make-package "STATE_MACHINE::COMMAND"))
(unless (find-package "STATE_MACHINE::COMMANDREQUEST")
  (make-package "STATE_MACHINE::COMMANDREQUEST"))
(unless (find-package "STATE_MACHINE::COMMANDRESPONSE")
  (make-package "STATE_MACHINE::COMMANDRESPONSE"))

(in-package "ROS")





(defclass state_machine::CommandRequest
  :super ros::object
  :slots (_cmd ))

(defmethod state_machine::CommandRequest
  (:init
   (&key
    ((:cmd __cmd) 0)
    )
   (send-super :init)
   (setq _cmd (round __cmd))
   self)
  (:cmd
   (&optional __cmd)
   (if __cmd (setq _cmd __cmd)) _cmd)
  (:serialization-length
   ()
   (+
    ;; int8 _cmd
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _cmd
       (write-byte _cmd s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _cmd
     (setq _cmd (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _cmd 127) (setq _cmd (- _cmd 256)))
   ;;
   self)
  )

(defclass state_machine::CommandResponse
  :super ros::object
  :slots (_response ))

(defmethod state_machine::CommandResponse
  (:init
   (&key
    ((:response __response) "")
    )
   (send-super :init)
   (setq _response (string __response))
   self)
  (:response
   (&optional __response)
   (if __response (setq _response __response)) _response)
  (:serialization-length
   ()
   (+
    ;; string _response
    4 (length _response)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _response
       (write-long (length _response) s) (princ _response s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _response
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _response (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass state_machine::Command
  :super ros::object
  :slots ())

(setf (get state_machine::Command :md5sum-) "fe45b9e717d330ed9d4cfc701593d88f")
(setf (get state_machine::Command :datatype-) "state_machine/Command")
(setf (get state_machine::Command :request) state_machine::CommandRequest)
(setf (get state_machine::Command :response) state_machine::CommandResponse)

(defmethod state_machine::CommandRequest
  (:response () (instance state_machine::CommandResponse :init)))

(setf (get state_machine::CommandRequest :md5sum-) "fe45b9e717d330ed9d4cfc701593d88f")
(setf (get state_machine::CommandRequest :datatype-) "state_machine/CommandRequest")
(setf (get state_machine::CommandRequest :definition-)
      "int8 cmd
---
string response

")

(setf (get state_machine::CommandResponse :md5sum-) "fe45b9e717d330ed9d4cfc701593d88f")
(setf (get state_machine::CommandResponse :datatype-) "state_machine/CommandResponse")
(setf (get state_machine::CommandResponse :definition-)
      "int8 cmd
---
string response

")



(provide :state_machine/Command "fe45b9e717d330ed9d4cfc701593d88f")


