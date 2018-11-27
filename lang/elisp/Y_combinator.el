(setq lexical-binding t)

;;; normal
(defun factorial (number)
  (if (eq number 1)
      1
    (* number (factorial (- number 1)))))

(factorial 4)
(factorial 5)


(lambda (fact)
  (lambda (number)
    (if (eq number 1)
        1
      (* number (funcall fact (- number 1))))))


(let ((proto-factorial (lambda (fact)
                         (lambda (number)
                           (if (eq number 1)
                               1
                             (* number (funcall fact (- number 1))))))))
  (eq (funcall 'factorial 4)
      (funcall (funcall proto-factorial 'factorial) 4)))

(let ((proto-factorial (lambda (fact)
                         (lambda (number)
                           (if (eq number 1)
                               1
                             (* number (funcall fact (- number 1))))))))
  (funcall (funcall proto-factorial proto-factorial) 4))

;;; meta-factorial
(lambda (fun)
  (lambda (number)
    (if (eq number 1)
        1
      (* number (funcall (funcall fun fun) (- number 1))))))

(let ((meta-factorial (lambda (fun)
                        (lambda (number)
                          (if (eq number 1)
                              1
                            (* number (funcall (funcall fun fun) (- number 1))))))))
  (eq (funcall 'factorial 4)
      (funcall (funcall meta-factorial meta-factorial) 4)))

(defun Y-Combinator-lazy (fun)
  (funcall (lambda (r)
             (funcall fun (funcall r r)))
           (lambda (r)
             (funcall fun (funcall r r)))))

(defun Y-Combinator (f)
  (funcall (lambda (x)
             (funcall f (lambda (y)
                          (funcall (funcall x x) y))))
           (lambda (x)
             (funcall f (lambda (y)
                          (funcall (funcall x x) y))))))

(funcall
 (Y-Combinator (lambda (f)
                 (lambda (n)
                   (if (eq n 0)
                       1
                     (* n
                        (funcall f (1- n)))))))
 3)
