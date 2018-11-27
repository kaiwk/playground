(define-struct time (hour minute second))

(define TIME (make-time 2 30 50))

(define (time->seconds time)
  (+ (time-second time)
     (* 60 (+
            (time-minute time)
            (* 60 (time-hour time))))))
