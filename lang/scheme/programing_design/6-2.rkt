;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname 6-2) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
(require htdp/draw)
(define WIDTH 50)
(define HEIGHT 160)
(define BULB-RADIUS 20)
(define BULB-DISTANCE 10)

(define X-BULB (quotient WIDTH 2))
(define Y-RED (+ BULB-DISTANCE BULB-RADIUS))
(define Y-GREEN (+ Y-RED BULB-DISTANCE (* 2 BULB-RADIUS)))
(define Y-YELLOW (+ Y-GREEN BULB-DISTANCE (* 2 BULB-RADIUS)))


(start WIDTH HEIGHT)
(draw-solid-disk (make-posn X-BULB Y-RED) BULB-RADIUS 'red)
(draw-circle (make-posn X-BULB Y-GREEN) BULB-RADIUS 'green)
(draw-circle (make-posn X-BULB Y-YELLOW) BULB-RADIUS 'yellow)

;;; symbol -> bool
(define (clear-bulb color)
  (cond
   [(symbol=? color 'red)
    (and
     (draw-solid-disk (make-posn X-BULB Y-RED) BULB-RADIUS 'white)
     (draw-circle (make-posn X-BULB Y-RED) BULB-RADIUS 'red))]
   [(symbol=? color 'green)
    (and
     (draw-solid-disk (make-posn X-BULB Y-GREEN) BULB-RADIUS 'white)
     (draw-circle (make-posn X-BULB Y-GREEN) BULB-RADIUS 'green))]
   [(symbol=? color 'yellow)
    (and
     (draw-solid-disk (make-posn X-BULB Y-YELLOW) BULB-RADIUS 'white)
     (draw-circle (make-posn X-BULB Y-YELLOW) BULB-RADIUS 'YELLOW))]))

;;; symbol -> bool
(define (draw-bulb color)
  (cond
   [(symbol=? color 'red)
    (draw-solid-disk (make-posn X-BULB Y-RED) BULB-RADIUS 'red)]
   [(symbol=? color 'green)
    (draw-solid-disk (make-posn X-BULB Y-GREEN) BULB-RADIUS 'green)]
   [(symbol=? color 'yellow)
    (draw-solid-disk (make-posn X-BULB Y-YELLOW) BULB-RADIUS 'yellow)]))

;;; symbol -> bool
(define (switch close-color open-color)
  (and
   (clear-bulb close-color)
   (draw-bulb open-color)))

;;; symbol -> symbol
(define (next current-color)
  (cond
   [(symbol=? current-color 'red)
    (switch current-color 'green)]
   [(symbol=? current-color 'green)
    (switch current-color 'yellow)]
   [(symbol=? current-color 'yellow)
    (switch current-color 'red)]))
