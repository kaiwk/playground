;; define the value of PI
(define pi (* 4 (atan 1.0)))

;; degree -> radian
(define (radian deg)
  (* deg (/ pi 180.0)))

;; free fall time
(define (ff-time vy)
  (/ (* 2.0 vy) 9.8))

;; horizontal distance
(define (dx vx t) (* vx t))

;; distance
(define (distance v ang)
  (dx
    (* v (cos (radian ang)))
    (ff-time (* v (sin (radian ang))))))

;; test
(distance 40 30)
