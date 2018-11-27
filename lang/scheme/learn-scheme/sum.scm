;求和规则
; (define (<name> a b)
;   (if (> a b)
;     0
;     (+ (<term> a)
;        (<name> (<next> a) b)
;        )
;     )
;   )

; (define (sum a b)
;   (if (> a b)
;     0
;     (+ a
;        (sum (1+ a) b)
;        )
;     )
;   )

; (define (sum-sq a b)
;   (if (> a b)
;     0
;     (+ (* a a)
;        (sum-sq (1+ a) b)
;        )
;     )
;   )

(define (sum-all term a next b)
  (if (> a b)
    0
    (+ (term a)
       (sum-all term
                (next a)
                next
                b
                ))))

(define (sum-sq-two a b)
  (sum-all (lambda (x) x) a
           (lambda (x) (1+ x)) b))

(define (fixed-point f start)
  (define tolerance 0.00001)
  (define (close-enough? u v)
    (< (abs (- u v)) tolerance))
  (define (iter old new)
    (if (close-enough? old new)
      new
      (iter new (f new))))
  (iter start (f start))
  )

(define (sq x)
  (fixed-point
    (lambda (y) (/ (+ y (/ x y)) 2))
    1))
