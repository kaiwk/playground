;; Heigher Order Function

;; map
(define (double-list ls)
  (map (lambda (x) (* 2 x)) ls))

(define (minus-list ls0 ls1)
  (map - ls0 ls1))


;; filter
(define (get-even ls)
  (filter even? ls))

(define (filter-!10to100 ls)
  (filter (lambda (x)
            (cond
              ((< x 10) #t)
              ((> x 100) #t)
              (else #f)))
          ls))



;; sort, it is not a stable sort.
(define (sort-sin ls)
  (sort ls (lambda (x y)
             (cond ((< (sin x) (sin y)) #t)
                   (else #f)))))

(define (sort-by-length ls)
  (sort ls (lambda (x y)
             (if (< (length x) (length y))
               #t
               #f))))


;; apply
(define (square-list ls)
  (apply + ((lambda (x) (map (lambda (x) (* x x)) x)) ls)))

;; member-if
(define (member-if proc ls)
  (cond
    ((null? ls ) #f)
    ((proc (car ls)) ls)
    (else (member-if proc (cdr ls)))))

