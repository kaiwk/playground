road(a, b).
road(a, c).
road(b, d).
road(c, d).
road(d, e).
road(b, e).

path(X, Y) :- road(X, Y).
path(X, Y) :- road(X, Z), road(Z, Y).
