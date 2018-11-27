(define (area-of-disk r)
  (* 3.14 (* r r)))

;;; number number -> number
;;; calculate area of a ring which radius is 'outer', inner radius is 'inner'.
;;; (area-of-ring 5 3) => 50.24
(define (area-of-ring outer inner)
  (- (area-of-disk outer)
     (area-of-disk inner)))
