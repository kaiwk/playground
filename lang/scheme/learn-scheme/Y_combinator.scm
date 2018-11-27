;; http://mvanier.livejournal.com/2897.html
(define almost-fact
  (lambda (f)
    (lambda (n)
      (if (= n 0)
          1
          (* n (f (- n 1)))))))

(define identity (lambda (x) x))
(define fact0 (almost-fact identity))
(define fact1 (almost-fact fact0))
(define fact2 (almost-fact fact1))
(define fact3 (almost-fact fact2))
(define fact4 (almost-fact fact3))


(fact1 2)

;; fixpoint-function = (almost-factorial fixpoint-function)

;; fixpoint-function =
;; (almost-factorial
;;  (almost-factorial fixpoint-function))

;; = (almost-factorial
;;    (almost-factorial
;;     (almost-factorial fixpoint-function)))

;; = ...

;; = (almost-factorial
;;    (almost-factorial
;;     (almost-factorial
;;      (almost-factorial
;;       (almost-factorial ...)))))

;;; so the fix point of the almost-factorial is the factorial we want.
;;; Wouldn't it be nice if there was some magical higher-order function that would
;;; take as its input a function like almost-factorial, and would output its fixpoint function,
;;; which in that case would be factorial?
;;; That function exists, and it's the Y combinator.
;; Y is also known as the fixpoint combinator: it takes in a function and returns its fixpoint.

;; OK, it's time to derive Y.

;; Let's start by specifying what Y does:

;; (Y f) = fixpoint-of-f

;; What do we know about the fixpoint of f? We know that

;; (f fixpoint-of-f) = fixpoint-of-f

;; by the definition of what a fixpoint of a function is. Therefore, we have:

;; (Y f) = fixpoint-of-f = (f fixpoint-of-f)

;; and we can substitute (Y f) for fixpoint-of-f to get:

;; (Y f) = (f (Y f))

;; Voila! We've just defined Y. If we want it to be expressed as a Scheme function, we would have to write it like this:

;; (define (Y f) (f (Y f)))

;; or, using an explicit lambda expression, as:

;; (define Y
;;   (lambda (f)
;;     (f (Y f))))


;; However, there are two caveats regarding this definition of Y:

;; 1. It will only work in a lazy language (see below).

;; 2. It is not a combinator, because the Y in the body of the definition is a free variable which is only bound once the definition is complete.
;; In other words, we couldn't just take the body of this version of Y and plop it in wherever we needed it,
;; because it requires that the name Y be defined somewhere.

;; Nevertheless, if you're using lazy Scheme, you can indeed define factorials like this:

;; (define Y
;;   (lambda (f)
;;     (f (Y f))))

;; (define almost-factorial
;;   (lambda (f)
;;     (lambda (n)
;;       (if (= n 0)
;;           1
;;           (* n (f (- n 1)))))))

;; (define factorial (Y almost-factorial))

;; and it will work correctly.


;; However, there is a clever hack that we can use to save the day and define a version of Y that works in strict languages.
;; The trick is to realize that (Y f) is going to become a function of one argument. Therefore, this equality will hold:

;; (Y f) = (lambda (x) ((Y f) x))
