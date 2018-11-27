;; n!
(define (fact n)
  (if (= n 1)
    1
    (* n (fact (- n 1)))))

;; fibnacci
(define (fib x)
  (cond
    ((= x 0) 1)
    ((= x 1) 1)
    (else (+ (fib (- x 1)) (fib (- x 2))))))

;; summary the length of list
(define (my-length l)
  (if (null? l)
    0
    (+ 1 (my-length (cdr ls)))))

;; summary the value of list
(define (summary l)
  (if (null? l)
    0
    (+ (car l) (summary (cdr l)))))

;; remove X frome ls
(define (remove-x-from-list x ls)
  (if (null? ls)
    '()
    (let ((h (car ls)))
     ((if (eqv? x h)
        (lambda (y) y)
        (lambda (y) (cons h y)))
      (remove-x-from-list x (cdr ls))))))

;; find the location of the x
(define (position x ls)
  (position-aux x ls 0))

(define (position-aux x ls i)
  (cond
    ((null? ls) #f)
    ((eqv? x (car ls)) i)
    (else (position-aux x (cdr ls) (1+ i)))))

;; tail recursion
(define (fact-tail n) (fact-rec n n))

(define (fact-rec n p)
  (if (= 1 n)
    p
    (let ((m (- n 1)))
     (fact-rec m (* p m)))))
