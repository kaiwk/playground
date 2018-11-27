#lang htdp

(define-struct square (nw length))
(define-struct circle (center radius))


;;; 确定问题数据中有多少种不同的对象
;;; 给函数命名、说明输出数据的类型，输出数据的类型，指出函数的目的
;;; 创建说明输入输出关系的例子
;;; 设计主体
;;; shape -> number
(define (perimeter a-shape)
  (cond
   [(square? a-shape) (* 4 (square-length a-shape))]
   [(circle? a-shape) (* 2 pi (circle-radius a-shape))]))

(= (perimeter (make-square (make-posn 0 0) 10)) 40)
(= (perimeter (make-circle (make-posn 5 5) 5)) (* 2 pi 5))
