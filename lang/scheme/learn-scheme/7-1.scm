(define (throw v a)
  (let ((r (/ (* 4 a (atan 1.0)) 180)))
   (/ (* 2 v v (cos r) (sin r)) 9.8)))
