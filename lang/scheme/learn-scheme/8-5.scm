;; do test
(define (fact-do n)
  (do ((n1 n (1- n1)) (p n (* p (1- n1))))
    ((= n1 1) p)))

;; exercise 8-2.scm 1
(define (my-reverse ls)
  (do ((src ls (cdr src)) (des '() (cons (car src) des)))
    ((null? src) des)))

;; exercise 8-2.scm 2
(define (sum-of-list ls)
  (do ((src ls (cdr src)) (res 0 (+ res (car src))))
    ((null? src) res)))

;; exercise 8-3.scm 3
(define (string2num str)
  (do ((src (string->list str) (cdr src)) (res 0 (+ (* 10 res) (- (char->integer (car src)) 48))))
    ((null? src) res)))
