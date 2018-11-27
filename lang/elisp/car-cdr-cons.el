;; car: contents of address part of register
;; cdr: contents of decrement part of register

(car '(rose violet daisy buttercup))
(cdr '(rose violet daisy buttercup))

(cons 'rose '(violet daisy buffercup))
(cons '(rose violet) '(daisy buffercup))

(length '(rose violet daisy buttercup))
(length '())

(nthcdr 1 '(rose violet daisy buttercup))

(setq flowers '(rose violet daisy buttercup))

(setcar flowers 'rose!!!)
flowers

(setcdr flowers '(hello world))
flowers
