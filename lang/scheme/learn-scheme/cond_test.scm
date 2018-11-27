(define (fee age)
  (cond
    ((or (<= age 3) (>= age 65)) 0)
    ((<= 4 age 6) 0.5)
    ((<= 7 age 12) 1.0)
    ((<= 13 age 15) 1.5)
    ((<= 16 age 18) 1.8)
    (else 2.0)))


