#lang htdp

(define (distance-to-0 a-posn)
  (sqrt
   (+ (sqr (posn-x a-posn))
      (sqr (posn-y a-posn)))))

(distance-to-0 (make-posn 1 0))


(start 300 300)
(draw-solid-line (make-posn 1 1)
                 (make-posn 5 5)
                 'red)
(draw-solid-rect (make-posn 20 20)
                 40
                 100
                 'black)

(draw-circle (make-posn 150 150)
             150
             'red)
