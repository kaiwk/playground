;; loop 1-10
(define (looping)
  (let loop ((x 0))
    (if (< x 10)
      (begin
        (display x)
        (newline)
        (loop (+ 1 x))))))

;; fib
(define (fib n)
    (if (or (= n 1) (= n 2) (= n 0))
     1
     (+ (fib (- n 1)) (fib (- n 2)))))

;; fac
(define (fac n)
        (if (= n 0)
         1
         (* n (fac (- n 1)))))

;; fac tail recursive
(define (fac-h n res)
        (if (= n 0)
         res
         (fac-h (- n 1) (* n res))))

(define (fac-tail n)
        (fac-h n 1))

(define (fac-tail n init)
        (lambda (n product)
         (if (= n 0)
          product
          (fac-tail (- n 1) (* init n)))) n init)


