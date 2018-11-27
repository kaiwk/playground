(setq my-list '(how are you im fine))

(defun print-elements-of-list (my-list)
  (while my-list
    (print (car my-list))
    (setq my-list (cdr my-list))))

(print-elements-of-list my-list)

(defun triangle (number-of-rows)
  (let ((total 0)
	(row-number 1))
    (while (<= row-number number-of-rows)
      (setq total (+ total row-number))
      (setq row-number (1+ row-number)))
    total))

(triangle 7)

(defun triangle2 (number-of-rows)
  (let ((total 0)
	(row-number number-of-rows))
    (while (> row-number 0)
      (setq total (+ total row-number))
      (setq row-number (1- row-number)))
    total))

(= (triangle 4) (triangle2 4))

(defun print-element-of-list-recur (my-list)
  (print (car my-list))
  (if my-list
      (print-element-of-list-recur (cdr my-list))))

(print-element-of-list-recur my-list)


(defun triangle-recur (number)
  (if (= number 1)
      1
    (+ number
       (triangle-recur
	(1- number)))))

(triangle-recur 4)


(defun triangle-using-cond (number)
  (cond
   ((<= number 0) 0)
   ((= number 1) 1)
   ((> number 1)
    (+ number (triangle-using-cond (1- number))))))

(triangle-using-cond 4)

(defun triangle-square (number)
  (let ((row 1)
	(total 0))
    (while (<= row number)
      (setq total (+ total (* row row)))
      (setq row (1+ row)))
    total))

(triangle-square 3)

(defun triangle-square2 (number)
  (cond
   ((<= number 0 ) 0)
   ((= number 1) 1)
   ((> number 1)
    (+ (* number number)
       (triangle-square2 (1- number))))))

(triangle-square2 3)

(defun triangle-multi (number)
  (let ((row number)
	(total 1))
    (while (>= row 1)
      (setq total (* total row))
      (setq row (1- row)))
    total))

(triangle-multi 4)


(defun create-index-for-dfn ()
  (interactive)
  (save-excursion
    (mark-paragraph)
    (save-restriction
      (narrow-to-region (point) (mark))
      (let (dfns)
	(while (search-forward "@dfn" nil t)
	  (when (search-forward "{" nil t)
	    (let ((start (point)))
	      (when (search-forward "}" nil t)
		(forward-char -1)
		(let ((end (point)))
		  (setq dfns (cons (buffer-substring start end)
				   dfns)))))))
	(forward-paragraph -1)
	(dolist (dfn dfns)
	  (insert (concat "@cindex " dfn "\n")))))))


(defun improve-create-index-for-dfn ()
  (interactive)
  (save-excursion
    (mark-paragraph)
    (save-restriction
      (narrow-to-region (point) (mark))
      (let (dfns)
	(while (search-forward "@dfn" nil t)
	  (when (search-forward "{" nil t)
	    (let* ((start (point))
		   (end (when (search-forward "}" nil t)
			  (forward-char -1)
			  (point))))
	      (setq dfns (cons (buffer-substring start end)
			       dfns)))))
	(forward-paragraph -1)
	(dolist (dfn dfns)
	  (insert (concat "@cindex " dfn "\n")))))))
