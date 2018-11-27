(defun my/forward-sentence (&optional arg)
  (interactive "p")
  (or arg (setq arg 1))
  (while (< arg 0)
    (let ((par-beg
	   (save-restriction (start-of-paragraph-text) (point))))
      (if (re-search-backward
	   (concat sentence-end "[^ \t\n]") par-beg t)
	  (goto-char (1- (match-end 0)))
	(goto-char par-beg)))
    (setq arg (1+ arg)))
  (while (> arg 0)
    (let ((par-end
	   (save-excursion (end-of-paragraph-text) (point))))
      (if (re-search-forward (sentence-end) par-end t)
	  (skip-chars-backward " \t\n")
	(goto-char par-end)))
    (setq arg (1- arg))))


(defun my/search-for-blank-lines (arg)
  (interactive "p")
  (or
   arg (setq arg 1))
  (search-forward-regexp "^\n\n" nil nil arg))


(defun my/search-for-duplicated-word (arg)
  (interactive "p")
  (or arg
      (setq arg 1))
  (if (re-search-forward
       "\\b\\([^@ \n\t]+\\)[ \n\t]+\\1\\b" nil 'move)
      (message "Found duplicated word.")
    (message "Not found duplicated word.")))
