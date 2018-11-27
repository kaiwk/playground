;; Macro
(define-syntax nil?
  (syntax-rules ()
                ((_x)
                 (set! x '()))))

;;
(define-syntax when
  (syntax-rules ()
                ((_ pred b1 ...)
                 (if pred (begin b1 ...)))))

;; while loop
(define-syntax while
  (syntax-rules ()
                ((_ pred b1 ...)
                 (let loop () (when pred b1 ... (loop))))))

;; for loop
(define-syntax for
  (syntax-rules ()
                ((_ (i from to) b1 ...)
                 (let loop ((i from))
                  (when (< i to)
                    b1 ...
                    (loop (1+ i)))))))

;; practice1
(define-syntax unless
  (syntax-rules () ((_ pred b1 ...)
                    (if pred #f (begin b1 ...)))))

;; practice2
(define-syntax decf
  (syntax-rules ()
                ((_ x) (begin (set! x (- x 1))))
                ((_ x i) (begin (set! x (- x i))))))


;; super for
(define-syntax super-for
  (syntax-rules ()
                ((_ (i from to) b1 ...)
                 (let loop ((i from))
                  (when (< i to)
                    b1 ...
                    (loop (1+ i)))))
                ((_ (i from to step) b1 ...)
                 (let loop ((i from))
                  (when (< i to)
                    b1 ...
                    (loop (+ i step)))))))


;; test
(let ((i 0))
 (when (= i 0)
   (display "i == 0")
   (newline)))

(let ((i 1))
 (unless (= i 0)
   (display "Ohpps~")
   (newline)))

(let ((i 0))
 (while (< i 10)
        (display i)
        (if (= i 9) (newline) (display #\Space))
        (set! i (+ i 1))))

(for (i 0 10)
     (display i)
     (if (= i 9) (newline) (display #\Space)))

(let ((i 0) (j 1))
 (decf i 11)
 (decf j)
 (display (list 'i '= i))
 (newline)
 (display (list 'j '= j))
 (newline))


(super-for (i 0 10 2)
     (display i)
     (display #\Space))

(begin (newline))


