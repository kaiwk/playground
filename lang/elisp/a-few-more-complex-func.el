(defun my-copy-to-buffer (buffer start end)
  (interactive "BMy Copy to Buffer: \nr")
  (let ((oldbuf (current-buffer)))
    (save-excursion
      (set-buffer (get-buffer-create buffer))
      (erase-buffer)
      (save-excursion
	(insert-buffer-substring oldbuf start end)))))


(defun my-insert-buffer (buffer)
  (interactive "*bMy insert to buffer: ")
  (or (bufferp buffer)
      (setq buffer (get-buffer buffer)))
  (let (start end newmark)
    (save-excursion
      (save-excursion
	(set-buffer buffer)
	(setq start (point-min)
	      end (point-max)))
      (insert-buffer-substring buffer start end)
      (setq newmark (point)))
    (push-mark newmark)))


(defun my-beginning-of-buffer (&optional arg)
  "\(goto-char (point-min))"
  (interactive "P")
  (push-mark)
  (goto-char
   (if arg
       (if (> (buffer-size) 10000)
	   (* (prefix-numeric-value arg)
	      (/ (buffer-size) 10))
	 (/ (+ 10 (* (buffer-size)
		     (prefix-numeric-value arg)))
	    10))
     (point-min)))
  (if arg (forward-line 1)))


(defun if-greater-than-fill-column (&optional arg)
  "'p' means applying prefix-numeric-value,
while 'P' means apply current-prefix-arg which is default nil."
  (interactive "P")
  (let ((num (or arg 56)))
    (if (> num fill-column)
	(message "%s greater than fill-column." num)
      (message "%s not greater than fill-column." num))))
