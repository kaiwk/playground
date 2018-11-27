loves(romeo, juliet).
loves(juliet, romeo) :- loves(romeo, juliet).

male(albert).
male(bob).
male(bill).
male(carl).
male(charlie).
male(dan).
male(edward).


female(alice).
female(betsy).
female(diana).

parent(albert, bob).
parent(albert, betsy).
parent(albert, bill).

parent(alice, bob).
parent(alice, betsy).
parent(alice, bill).

parent(bob, carl).
parent(bob, charlie).

get_grandchild :-
    parent(albert, X),
    parent(X, Y),
    write('alberts grandchild is '),
    write(Y), nl.

get_parent :-
    parent(X, carl),
    parent(X, charlie),
    format('~w ~s grandparent ~n', [X, 'is the']).

brother(bob, bill).

grand_parent(X, Y) :-
    parent(X, Z),
    parent(Z, Y).

blushes(X) :- human(X).
human(kermit).

what_grade(5) :-
    write('Go to kindergarden.').

what_grade(6) :-
    write('Go to 1st.').

what_grade(Other) :-
    Grade is Other-5,
    format('Go to ~w.', [Grade]).
