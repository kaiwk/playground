;; 下面的定义的函数有三种调用方式：
;; 在Lisp程序里调用，比如(get-dir "/tmp")。
;; 交互式调用，比如M-x get-dir。
;; 带参数交互式调用，比如C-u M-x get-dir。

(defun get-dir (dir)
  "This function can be called non-interactively and interactively."
  (interactive (list (if current-prefix-arg
		   (file-name-as-directory
		    (read-directory-name "A directory: "
					 default-directory))
		   default-directory)))
  (print dir))
