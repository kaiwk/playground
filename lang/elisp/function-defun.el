(buffer-name)
(buffer-file-name)
(current-buffer)
(point)
(point-min)
(point-max)

(defun multiply-by-seven (number)
  (interactive "p")
  (message "The result is %d" (* 7 number)))

(defun print-region (begin end)
  (interactive "r")
  (message "The region begin is %d, The region end is %d" begin end))

(defun print-buffer (buffername)
  (interactive "BAppend to buffer:")
  (message "The buffer name is: %s" buffername))

(defun print-buffer-and-region (buffername begin end)
  (interactive "BAppend to buffer: \nr")
  (message "The buffer name is: %s, begin: %d, end: %d" buffername begin end))


(let ((zebra 'stripes)
      (tiger 'fierce))
  (message "One kind of animal has %s and other is %s" zebra tiger))

(let ((birch 3)
      pine
      fir
      (oak 'some))
  (message "Here are %d variables with %s, %s, and %s value" birch pine fir oak))

(let ((bn (buffer-name))
      (bs (buffer-size)))
  (message "This buffer is %s and has %d characters." bn bs))

(if (> 5 4)
    (message "5 greater than 4!"))


(defun type-of-animal (characteristic)
  (if (eq characteristic 'fierce)
      (message "It's a tiger!")))

(type-of-animal 'fierce)

(defun count-chars-until-current-cursor ()
  (interactive)
  (message "We are %d characters into this buffer."
	   (- (point)
	      (save-excursion
		(goto-char (point-min))
		(point)))))


(if (string= (int-to-string 25)
	     (substring (emacs-version) 10 12))
    (message "This is version 25 emacs!"))
