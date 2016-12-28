/*Pour afficher les etapes successives, tapez "resoudre." */

action([X,X,Chevre,Chou],transfert_loup(X,Y),[Y,Y,Chevre,Chou]).
action([X,Loup,X,Chou], transfert_chevre(X,Y),[Y,Loup,Y,Chou]).
action([X,Loup,Chevre,X], transfert_chou(X,Y),[Y,Loup,Chevre,Y]).
action([X,Loup,Chevre,Chou], tout_seul(X,Y),[Y,Loup,Chevre,Chou]).

egaux(X,X).

reussite([Peon,Loup,Chevre,Chou]) :- egaux(Peon,Chevre);(egaux(Peon,Loup),egaux(Peon,Chou)).

but([rive2,rive2,rive2,rive2],[]).
but(Avant,[Action|Reste]) :- action(Avant,Action,Apres), reussite(Apres), but(Apres,Reste), write(Action), nl, !.

check(List) :- but([rive1,rive1,rive1,rive1], List), !.

solve(Y) :- length(X, Y), check(X), !.
solve(Y) :- X is Y + 1, solve(X).

resoudre :- solve(0).