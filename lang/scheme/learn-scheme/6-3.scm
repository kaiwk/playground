(define get-score
  (lambda (score)
    (cond
      ((>= score 80) #\A)
      ((<= 60 score 79) #\B)
      ((<= 40 score 59) #\C)
      ((< score 40) #\D))))
