;; absolute value
(define myabs
  (lambda (num)
    (if (> num 0)
      num
      (- num))))

;; 倒数
(define inverse
  (lambda (num)
    (if (= num 0)
      #f
      (/ 1 num))))

;; ASCII value
(define asc-value
  (lambda (num)
    (if (<= 33 num 126)
      (integer->char num)
      #f)))
