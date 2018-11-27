(define let-hello (let ((s "you")) (string-append "Hello," s "!")))
(define lambda-hello ((lambda (s) (string-append "Hello," s "!")) "you"))
