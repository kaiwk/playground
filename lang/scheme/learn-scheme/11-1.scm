;; closure
(define bank-account
  (let ((balance 10))
   (lambda (n)
     (set! balance (+ n balance))
     balance)))

(define (make-bank-account amount)
  (lambda (n)
    (let ((m (+ amount n)))
     (if (negative? m)
       'error
       (begin
         (set! amount m)
         amount)))))

(define make-bank (make-bank-account 10))


;; queue
(define (make-queue)
  (cons '() '()))

(define (enqueue! queue obj)
  (let ((lobj (cons obj '())))
   (if (null? (car queue))
     (begin
       (set-car! queue lobj)
       (set-cdr! queue lobj))
     (begin
       (set-cdr! (cdr queue) lobj)
       (set-cdr! queue lobj)))
   (car queue)))

(define (dequeue! queue)
  (let ((obj (car (car queue))))
   (set-car! queue (cdr (car queue)))
   obj))


