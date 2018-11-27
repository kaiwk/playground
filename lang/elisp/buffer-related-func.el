(beginning-of-buffer)

(defun simplified-beginning-of-buffer ()
  (interactive)
  (push-mark)
  (goto-char (point-min)))


(defun mark-whole-buffer ()
  (interactive)
  (push-mark (point))
  (push-mark (point-max))
  (push-mark (point-min)))

(defun my/append-to-buffer (buffer start end)
  (interactive "BMy Append to Buffer: \nr")
  (let ((oldbuf (current-buffer)))
    (save-excursion
      (set-buffer (get-buffer-create buffer))
      (insert-buffer-substring oldbuf start end))))

(defun simplified-end-of-buffer ()
  (interactive)
  (push-mark)
  (goto-char (point-max)))
