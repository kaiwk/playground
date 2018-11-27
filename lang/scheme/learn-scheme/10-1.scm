;; read-file
(define (read-file file-name)
  (let ((p (open-input-file file-name)))
   (let loop ((ls1 '()) (c (read-char p)))
    (if (eof-object? c)
      (begin
        (close-input-port p)
        (list->string (reverse ls1))
        )
      (loop (cons c ls1) (read-char p))))))



;; practice 1
(define (read-lines file-name)
  (with-input-from-file file-name
                        (lambda ()
                          (let loop ((ls1 '()) (s (read-char)))
                           (if (eof-object? s)
                             (reverse ls1)
                             (loop (cons s ls1) (read-char)))))))


;; tricky begin

(define (trick! file-name)
  (display
    (let ((f (open-input-file file-name)))
     (let continue ((ls '()) (c (read-char f)))
      (if (eof-object? c)
        (begin
          (close-input-port f)
          (string-append "(" (list->string (remove-last (reverse ls))) ")\n"))
        (continue (cons c ls) (read-char f)))))))

(define (remove-last ls)
  (let loop ((src ls) (des '()))
   (if (= 1 (length src))
     (reverse des)
     (loop (cdr src) (cons (car src) des)))))

;; triky end


;; practice 2
;; copy file
(define (my-copy-file from to)
  (let ((pfr (open-input-file from)) (pto (open-output-file to)))
   (let loop ((c (read-char pfr)))
    (if (eof-object? c)
      (begin
        (close-input-port pfr)
        (close-output-port pto))
      (begin
        (write-char c pto)
        (loop (read-char pfr)))))))

;; practice 3
(define (print-lines . line)
  (let loop ((ls line))
   (if (pair? ls)
     (begin
       (display (car ls))
       (newline)
       (loop (cdr ls))))))


