(defun my/zap-to-char (arg char)
  (interactive "*p\ncMy Zap to char: ")
  (kill-region (point)
	       (progn
		 (search-forward
		  (char-to-string char) nil nil arg)
		 (point))))


(defun my/kill-region (beg end)
  (interactive "*r")
  (copy-region-as-kill beg end)
  (delete-region beg end))


(defun my/copy-region-as-kill (beg end)
  (interactive "r")
  (if (ea last-command 'kill-region)
      (kill-append (buffer-substring beg end) (< end beg))
    (setq kill-ring
	  (cons (buffer-substring beg end) kill-ring))
    (if (> (length kill-ring) kill-ring-max)
	(setcdr (nthcdr (1- kill-ring-max) kill-ring) nil)))
  (setq this-command 'kill-region)
  (setq kill-ring-yank-pointer kill-ring))


(defun my/kill-append (string before-p)
  (setcar kill-ring
	  (if before-p
	      (concat string (car kill-ring))
	    (concat (car kill-ring) string))))

(concat "abc" "dfg")
