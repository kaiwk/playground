;; scale a list
(define (scale-list ls s)
  (if (null? ls)
    '()
    (cons (* s (car ls))
          (scale-list (cdr ls) s))))
