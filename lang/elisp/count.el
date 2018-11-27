(defun my/count-words-region (beginning end)
  (interactive "r")
  (message "Counting words in region...")
  (save-excursion
    (goto-char beginning)
    (let ((count 0))
      (while (and (< (point) end)
		  (re-search-forward "\\w+\\W*" end t))
	(setq count (1+ count)))
      (cond ((zerop count)
	     (message "The region does not have any words."))
	    ((= 1 count)
	     (message "The region has 1 word."))
	    (t
	     (message "The region has %d words." count))))))


(defun my/count-words-region2 (beginning end)
  (interactive "r")
  (message "Counting words in region...")
  (save-excursion
    (goto-char beginning)
    (let ((count (count-words-recursive end)))
      (cond ((zerop count)
	     (message "The region does not have any words."))
	    ((= 1 count)
	     (message "The region has 1 word."))
	    (t
	     (message "The region has %d words." count))))))

(defun count-words-recursive (end)
  (if (and (< (point) end)
	   (re-search-forward "\\w+\\W*" end t))
      (1+ (count-words-recursive end))
    0))


(defun my/count-punctuation (beginning end)
  (interactive "r")
  (message "Counting punctuation region...")
  (save-excursion
    (goto-char beginning)
    (let ((count 0))
      (while (and (< (point) end)
		  (re-search-forward "[,.:;\"'!?]" end t))
	(setq count (1+ count)))
      (cond
       ((zerop count)
	(message "The region does not have any words."))
       ((= 1 count)
	(message "The region has 1 punctuation."))
       (t
	(message "The region has %d punctuations." count))))))


(defun my/count-punctuation2 (beginning end)
  (interactive "r")
  (message "Counting punctuation in region...")
  (save-excursion
    (goto-char beginning)
    (let ((count (count-punctuation-recursive end)))
      (cond ((zerop count)
	     (message "The region does not have any punctuations."))
	    ((= 1 count)
	     (message "The region have 1 punctuation."))
	    (t
	     (message "The region have %d punctuations." count))))))

(defun count-punctuation-recursive (end)
  (if (and (< (point) end)
	   (re-search-forward "[,.:;'\"!?]" end t))
      (1+ (count-punctuation-recursive end))
    0))
