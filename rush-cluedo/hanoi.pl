/*jeu de Hanoi : Creez un programme en prolog qui resout une tour de hanoi. La solution sera lancee avec Hanoi/1, le predicat correspondant au nombre d'etages qu'a cette tour :)*/

mouv(0, _, _ , _).
mouv(N, A, B, C) :- K is (N - 1), mouv(K, A, C, B),
write(transport), write(' '), write(A),write(' '), write(sur),write(' '), write(C), nl,
mouv(K, B, A, C).
hanoi(N) :- mouv(N, gauche, milieu, droite), !.
