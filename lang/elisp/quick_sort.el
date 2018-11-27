(defun qs (ls)
  "quick sort"
  (if (null ls)
      '()
    (let* ((pivot (car ls))
	   (rest (cdr ls))
	   (lesser (remove-if-not
		    (lambda (x) (<= x pivot)) rest))
	   (greater (remove-if-not
		     (lambda (x) (> x pivot)) rest)))
      (append (qs lesser) (list pivot) (qs greater)))))

(qs '(10 9 4 5 7 1))
