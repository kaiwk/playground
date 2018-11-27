;; exercise letrec
(define (fact-letrec n)
  (letrec ((iter (lambda (n1 p)
                   (if (= n1 1)
                     p
                     (let ((m (1- n1)))
                      (iter m (* p m)))))))
    (iter n n)))


;; exerciese 8-2.scm 1
(define (my-reverse ls)
  (letrec ((iter (lambda (src des)
                   (if (null? src)
                     des
                     (iter (cdr src)
                           (cons (car src) des))))))
    (iter ls '())))

;; exercise 8-2.scm 2
(define (sum-of-list ls)
  (letrec ((iter (lambda (src sum)
                   (if (null? src)
                     sum
                     (iter (cdr src) (+ sum (car src)))))))
    (iter ls 0)))

;; exercise 8-2.scm 3
(define (string2num str)
  (letrec ((iter (lambda (src res)
                   (if (null? src)
                     res
                     (let ((temp (char->integer (car src))))
                      (let ((n (- temp 48)))
                       (iter (cdr src) (+ (* 10 res) n))))))))
    (iter (string->list str) 0)))
