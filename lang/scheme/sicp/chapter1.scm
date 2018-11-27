;;; 1.1
(define (average x y)
  (/ (+ x y) 2))

(define (square x)
  (* x x))

(define (kermit/sqrt x)
  (sqrt-iter 1.0 x))

(define (sqrt-iter guess x)
  (if (good-enough? guess x)
      guess
      (sqrt-iter (improve guess x) x)))

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) 0.001))

(define (improve guess x)
  (average guess (/ x guess)))

;; (kermit/sqrt 8)


;;; 1.2
;; 1 1 2 3 5 8
(define (fibnacci n)
  (if (or (= 0 n) (= 1 n))
      1
      (+ (fibnacci (- n 2)) (fibnacci (- n 1)))))

(define (fibnacci-iter a b index)
  (if (= index 0)
      b
      (fibnacci-iter b (+ a b) (- index 1))))

(define (fibnacci-better n)
  (fibnacci-iter 0 1 n))


(define (first-denomination kinds-of-coins)
  (cond ((= kinds-of-coins 1) 1)
        ((= kinds-of-coins 2) 5)
        ((= kinds-of-coins 3) 10)
        ((= kinds-of-coins 4) 25)
        ((= kinds-of-coins 5) 50)))

(define (cc amount kinds-of-coins)
  (cond ((= amount 0) 1)
        ((or (< amount 0) (= kinds-of-coins 0)) 0)
        (else  (+
                (cc amount (- kinds-of-coins 1))
                (cc (- amount (first-denomination kinds-of-coins))
                    kinds-of-coins)))))

(define (count-change amount)
  (cc amount 5))

(count-change 100)


;;; 1.3
(define (my-loop func range)
  (let ((start (car range))
        (end (cdr range)))
    (if end
        (if (>= end start)
            (func)
            (my-loop func (con (start))))
        (if (> start 0)))))
