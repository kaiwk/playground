(defun my/count-words-in-func ()
  (interactive)
  (save-excursion
    (beginning-of-defun)
    (let ((count (count-words-in-func-help)))
      (cond
       ((zerop count)
	(message "The function does not have any words or symbols."))
       ((= 1 count)
	(message "The function has 1 word or symbol."))
       (t
	(message "The function has %d words or symbols." count)))
      count)))


(defun count-words-in-func-help ()
  (let ((count 0)
	(end (save-excursion (end-of-defun) (point))))
    (while (and (< (point) end)
		(re-search-forward "\\(\\w\\|\\s_\\)+[^ \t\n]*[ \t\n]*" end t))
      (setq count (1+ count)))
    count))

(defun my/lengths-list-file (filename)
  (message "Working on %s..." filename)
  (save-excursion
    (let ((buffer (find-file-noselect filename))
	  (lengths-list))
      (set-buffer buffer)
      (setq buffer-read-only t)
      (widen)
      (goto-char (point-min))
      (while (re-search-forward "^(defun" nil t)
	(setq lengths-list
	      (cons (my/count-words-in-func) lengths-list)))
      (kill-buffer buffer)
      lengths-list)))


(defun lengths-list-many-files (list-of-files)
  (let (lengths-list)
    (while list-of-files
      (setq lengths-list
	    (append lengths-list
		    (my/lengths-list-file
		     (expand-file-name (car list-of-files)))))
      (setq list-of-files (cdr list-of-files)))
    lengths-list))


(defun recursive-lengths-list-many-files (list-of-files)
  (if list-of-files
      (append (my/lengths-list-file
	       (expand-file-name (car list-of-files)))
	      (recursive-lengths-list-many-files (cdr list-of-files)))))

(defvar top-of-ranges
  '(10 20 30 40 50
       60 70 80 90 100
       110 120 130 140
       150 160 170 180
       190 200 210 220
       230 240 250 260
       270 280 290 300)
  "List specifying ranges for `defuns-per-range'.")


(defun defuns-per-range (sorted-lengths top-of-ranges)
  (let ((top-of-range (car top-of-ranges))
	(number-within-range 0)
	defuns-per-range-list)

    (while top-of-ranges

      (while (and
	      (car sorted-lengths)
	      (< (car sorted-lengths) top-of-range))

	(setq number-within-range (1+ number-within-range))
	(setq sorted-lengths (cdr sorted-lengths)))

      (setq defuns-per-range-list
	    (cons number-within-range
		  defuns-per-range-list))
      (setq number-within-range 0)

      (setq top-of-ranges (cdr top-of-ranges))
      (setq top-of-range (car top-of-ranges)))
    (setq defuns-per-range-list
	  (cons (length sorted-lengths)
		defuns-per-range-list))
    (nreverse defuns-per-range-list)))

;; (setq top-of-ranges '(110 120 130 140 150
;; 			  160 170 180 190 200))

;; (setq sorted-lengths
;;       '(85 86 110 116 122 129 154 176 179 200 265 300 300))

;; (defuns-per-range sorted-lengths top-of-ranges)

(defuns-per-range
  (recursive-lengths-list-many-files
   (directory-files "~/.emacs.d/config-lisp/" t "\\.el$"))
  top-of-ranges)



(defvar graph-blank " "
  "String used as blank in graph, usually an asterisk.")

(defvar graph-symbol "*"
  "String used as symbol in graph, usually an blank.")


(defun column-of-graph (max-graph-height actual-height)
  (let ((insert-list nil)
	(number-of-top-blanks
	 (- max-graph-height actual-height)))

    ;; fill in asterisk
    (while (> actual-height 0)
      (setq insert-list (cons graph-symbol insert-list))
      (setq actual-height (1- actual-height)))

    ;; fill in blanks
    (while (> number-of-top-blanks 0)
      (setq insert-list (cons graph-blank insert-list))
      (setq number-of-top-blanks
	    (1- number-of-top-blanks)))

    insert-list))

(defun graph-body-print (numbers-list)
  (let ((height (apply 'max numbers-list))
	(symbol-width (length graph-blank))
	from-position)
    (while numbers-list
      (setq from-position (point))
      (insert-rectangle
       (column-of-graph height (car numbers-list)))
      (goto-char from-position)
      (forward-char symbol-width)
      ;; draw graph column by column
      (sit-for 0)
      (setq numbers-list (cdr numbers-list)))
    (forward-line height)
    (insert "\n")))
