;;; undo scroll
(defvar unscroll-point (make-marker)
  "cursors position for next call to 'unscroll'.")
(defvar unscroll-window-start (make-marker)
  "window start for next call to 'unscroll'.")
(defvar unscroll-hscroll nil
  "Hscroll for next call to 'unscroll'.")

(put 'scroll-up 'scrollable t)
(put 'scroll-down 'scrollable t)
(put 'scroll-left 'scrollable t)
(put 'scroll-right 'scrollable t)

(defun unscroll-maybe-remember ()
  (if (not (get last-command 'scrollable))
      (progn
	(set-marker unscroll-point (point))
	(set-marker unscroll-window-start (window-start))
	(setq unscroll-hscroll (window-hscroll)))))

(defadvice scroll-up (before remember-for-unscroll
			     activate compile)
  "Remeber where we started from, for 'unscroll'."
  (unscroll-maybe-remember))

(defadvice scroll-down (before remember-for-unscroll
			       activate compile)
  "Remeber where we started from, for 'unscroll'."
  (unscroll-maybe-remember))

(defadvice scroll-left (before remember-for-unscroll
			       activate compile)
  "Remeber where we started from, for 'unscroll'."
  (unscroll-maybe-remember))

(defadvice scroll-right (before remember-for-unscroll
				activate compile)
  "Remeber where we started from, for 'unscroll'."
  (unscroll-maybe-remember))


(defun kermit/unscroll ()
  "Revert to 'unscroll-point' and 'unscroll-window-start'."
  (interactive)
  (if (not (marker-buffer unscroll-point))
      (error "Cannot unscroll yet.")
    (progn
      (goto-char unscroll-point)
      (set-window-start nil unscroll-window-start)
      (set-window-hscroll nil unscroll-hscroll))))
