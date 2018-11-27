(define (inches->cm inch)
  (* 2.54 inch))

(define (feet->inches feet)
  (* 12 feet))

(define (yards->feet yard)
  (* 2 yard))

(define (rods->yards rods)
  (* 5.5 rods))

(define (furlongs->rods furlongs)
  (* 40 furlongs))

(define (miles->furlongs miles)
  (* 8 miles))

(define (feet->cm feet)
  (inches->cm (feet->inches feet)))

(define (yards->cm yards)
  (feet->cm (yards->feet yards)))

(define (rods->inches rods)
  (feet->inches
   (yards->feet
    (rods->yards rods))))

(define (miles->feet miles)
  (miles->feet
   (miles->furlongs miles)))
