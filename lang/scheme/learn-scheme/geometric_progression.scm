;; 几何增长数列之和
;; a0 * (1 - r^n) / (1 - r)     r != 1
;; a0 * n                       r = 1

(define (geometric-progression a0 r n)
  ( * a0
      (if (= r 1)
        n
        (/ (- 1 (expt r n)) (- 1 r)))))
