% facts
happy(albert).
happy(alice).
happy(bob).
happy(bill).
with_alber(alice).

near_water(bob).

% rules
runs(albert) :-
    happy(albert).


dances(alice) :-
    happy(alice),
    with_alber(alice).

does_alice_dance :- dances(alice),
		    write('when alice alice is happy and with albert she dances.').

swims(bob) :-
    happy(bob),
    near_water(bob).
