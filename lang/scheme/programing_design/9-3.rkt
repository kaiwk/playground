(define (contains-doll? a-list-of-symbol)
  (cond
   [(empty? a-list-of-symbol) false]
   [else
    (cond
     [(symbol=? 'doll (car a-list-of-symbol)) true]
     [else (contains-doll? (rest a-list-of-symbol))])]))

(contains-doll? '(hello asdfad adsf dol))
