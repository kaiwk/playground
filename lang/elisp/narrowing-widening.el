(defun my/what-line ()
  (interactive)
  (save-restriction
    (widen)
    (save-excursion
      (beginning-of-line)
      (message "Line %d"
	       (1+ (count-lines 1 (point)))))))


(defun display-begin-60-char ()
  (interactive)
  (save-restriction
    (widen)
    (message (buffer-substring-no-properties (point-min) 60))))
