(define (demo x)
  ((lambda (y)
     (* x y)) 5))

(define make-counter
  (lambda (N)
    (lambda ()
      (set! N (1+ N))
      N)))

(define C1 (make-counter 1))
(define C2 (make-counter 10))

(define fruit-store
  (lambda (N)
    (lambda (fruit-name)
      (if (equal? fruit-name 'apple)
          (set! N (1+ N)))
      N)))

(define F1 (fruit-store 0))

;;; estimate pi
(define (cesaro)
  (= (gcd (random-integer 10000)
          (random-integer 10000))
     1))

(define (monte-carlo trials experiment)
  (define (iter remaining passed)
    (cond ((= remaining 0)
           (/ passed trials))
          ((experiment)
           (iter (-1+ remaining)
                 (1+ passed)))
          (else
           (iter (-1+ remaining)
                 passed))))
  (iter trials 0))

(define (estimate-pi n)
  (sqrt (/ 6 (monte-carlo n cesaro))))
