;; practice 1
(define (identity x) x)

;; answer1
(define (title-style str)
  (let loop ((ls (string->list str)) (w #t) (acc '()))
   (if (null? ls)
     (list->string (reverse acc))
     (let ((c (car ls)))
      (loop (cdr ls)
            (char-whitespace? c)
            (cons ((if w
                     char-upcase
                     identity) c) acc))))))

;; answer2
;; string is read-only
(define (title-style-string str)
  (let ((n (string-length str)) (str0 (string-copy str)))
   (let loop ((w #t) (i 0))
    (if (= i n)
      str0
      (let ((c (string-ref str0 i)))
       (if w (string-set! str0 i (char-upcase c)))
       (loop (char-whitespace? c) (+ i 1)))))))


