;; reverse a sequence
(define (my-reverse-rec src des)
  (if (null? src)
    des
    (my-reverse-rec (cdr src) (cons (car src) des))))

(define (my-reverse ls)
  (my-reverse-rec ls '()))


;; sum of list
(define (sum-of-list-rec ls res)
  (if (null? ls)
    res
    (sum-of-list-rec (cdr ls) (+ res (car ls)))))

(define (sum-of-list ls)
  (sum-of-list-rec ls 0))

;; string to num
(define (string2num str)
  (string2num-rec (string->list str) 0))

(define (string2num-rec str res)
  (if (null? str)
    res
    (string2num-rec (cdr str)
                    (+ (* 10 res) (- (char->integer (car str)) 48)))))

