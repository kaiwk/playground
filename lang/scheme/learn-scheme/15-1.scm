;; vector
(define (same-length v1 v2)
  (let ((len1 (vector-length v1))
        (len2 (vector-length v2)))
    (if (= len1 len2)
      #t
      #f
      )))

(define (vector-add v1 v2)
  (if (same-length v1 v2)
      (let ((v (make-vector (vector-length v1))))
       (let loop ((i 0))
        (if (= i (vector-length v1))
          v
          (begin
            (vector-set! v i (+ (vector-ref v1 i) (vector-ref v2 i)))
            (loop (1+ i))))))
      'Error))

(define (vector-muti v1 v2)
  (if (same-length v1 v2)
    (let ((len (vector-length v1)))
     (let ((v (make-vector len)))
      (let loop ((i 0))
       (if (= i len)
         v
         (begin
           (vector-set! v i (* (vector-ref v1 i) (vector-ref v2 i)))
           (loop (1+ i)))))))))


