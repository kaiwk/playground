(define func1
  (lambda (num1 num2 num3)
    (if (and (> num1 0) (> num2 0) (> num3 0))
      (* num1 num2 num3))))

(define func2
  (lambda (num1 num2 num3)
    (if (or (> 0 num1) (> 0 num2) (> 0 num3))
      (* num1 num2 num3))))
