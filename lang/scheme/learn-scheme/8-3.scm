;; let loop
(define (fact-let n)
  (let loop ((n1 n) (p n))
   (if (= n1 1)
     p
     (let ((m (- n1 1)))
      (loop m (* p m))))))

;; use let loop
;; exercise 8-1.scm 3
(define (remove-x ls x)
  (let loop ((src ls) (des '()))
   (if (null? src)
     (reverse des)
     (loop (cdr src)
           (if (eqv? x (car src))
             des
             (cons (car src) des))))))

;; exercise 8-1.scm 4
(define (index-of ls x)
  (let loop ((src ls) (i 0))
   (cond
     ((null? ls) #f)
     ((eqv? x (car src)) i)
     (else (loop (cdr src) (1+ i))))))


;; function range
(define (range n)
  (let loop ((ls '()) (i 0))
   (if (= i n)
     (reverse ls)
     (loop (cons i ls) (1+ i)))))
