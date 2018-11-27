(defun insert-current-time ()
  (interactive "*")
  (insert (format-time-string "%H:%M %p" (current-time))))

(defvar insert-time-format "%X"
  "*Format for \\[insert-time] (c.f. 'format-time-string').")

(defvar insert-date-format "%x"
  "*Format for \\[insert-time] (c.f. 'format-date-string').")

(defun insert-time ()
  "Insert the current time according to insert-time-format."
  (interactive "*")
  (insert (format-time-string insert-time-format
                              (current-time))))

(defun insert-date ()
  "Insert the current date according to insert-date-format."
  (interactive "*")
  (insert (format-time-string insert-date-format
                              (current-time))))

(defvar writestamp-prefix "WRITESTAMP(("
  "*Unique string identifying start of writestamp.")

(defvar writestamp-suffix "))"
  "*Unique string identifying end of writestamp.")

(defvar writestamp-format "%x"
  "*Format for writestamp (c.f. 'format-time-string.)'")

(defun update-writestamp ()
  "Find writestamps and replace them with current time."
  (save-excursion
    (save-restriction
      (save-match-data
        (widen)
        (goto-char (point-min))
        (let ((regex (concat "^"
                             (regexp-quote writestamp-prefix)
                             "\\(.*\\)"
                             (regexp-quote writestamp-suffix)
                             "$")))
          (while (re-search-forward regex nil t)
            (replace-match (format-time-string writestamp-format
                                               (current-time))
                           t t nil 1)))))))

(add-hook 'first-change-hook 'update-writestamp nil t)

WRITESTAMP((20))
