;;; profit: number -> number
(define (profit ticket-price)
  (- (revenue ticket-price)
     (cost ticket-price)))

;;; revenue: number -> number
(define (revenue ticket-price)
  (* ticket-price (attendees ticket-price)))

;;; cost: number -> number
(define (cost ticket-price)
  (+ 180
     (* 0.04 (attendees ticket-price))))

;;; attendees: number -> number
(define (attendees ticket-price)
  (+ 120
     (* 15
        (/ (- 5 ticket-price) 0.1))))

(profit 5)
