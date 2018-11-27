#lang htdp

(start 300 300)

;;; (posn number symbol)
(define-struct circle (center radius color))

;;; draw a circle on the canva
(define (draw-a-circle a-circle)
  (draw-circle (circle-center a-circle)
               (circle-radius a-circle)
               (circle-color a-circle)))

;;; posn posn -> number
(define (distance-between a-posn b-posn)
  (sqrt (+
         (sqr (- (posn-x a-posn)
                 (posn-x b-posn)))
         (sqr (- (posn-y a-posn)
                 (posn-y b-posn))))))

;;; posn posn -> bool
(define (in-circle? a-circle a-posn)
  (if (< (distance-between a-posn (circle-center a-circle))
         (circle-radius a-circle))
      #t
      #f))

;;; test for in-circle
;; (in-circle? (make-circle (make-posn 6 2) 1 'red) (make-posn 6 1.5))
;; (in-circle? (make-circle (make-posn 6 2) 1 'red) (make-posn 8 6))

;;; circle number -> circle
(define (translate-circle a-circle delta)
  (make-circle (make-posn (+ (posn-x (circle-center a-circle)) delta)
                          (posn-y (circle-center a-circle)))
               (circle-radius a-circle)
               (circle-color a-circle)))

;;; circle -> none
(define (clear-a-circle a-circle)
  (draw-circle (circle-center a-circle)
               (circle-radius a-circle)
               'white))

;;; circle -> none
(define (draw-and-clear-circle a-circle)
  (and (draw-a-circle a-circle)
       (sleep-for-a-while 2)
       (clear-a-circle a-circle)))

;;; number circle -> none
(define (move-circle delta a-circle)
  (when (draw-and-clear-circle a-circle)
    (translate-circle a-circle delta)))

(draw-a-circle
 (move-circle 10
              (move-circle 10
                           (move-circle 10
                                        (move-circle 10 (make-circle (make-posn 30 30) 10 'red))))))
