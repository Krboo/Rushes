/* Pour afficher toutes les infos completees, tapez: "resoudre(X).". Pour savoir qui a le poisson, tapez: "the_fishman(X)." */
a_droite(X,Y) :- X is Y+1.
voisin_de(X,Y) :- a_droite(X,Y).
voisin_de(X,Y) :- a_droite(Y,X).



resoudre(Maisons) :-
Maisons =
[
maison(1,_,_,_,_,_) ,
maison(2,_,_,_,_,_) ,
maison(3,_,_,_,_,_) ,
maison(4,_,_,_,_,_) ,
maison(5,_,_,_,_,_)
],
member(maison(_,rouge,anglais,_,_,_),Maisons),
member(maison(_,_,suedois,_,_,chiens),Maisons),
member(maison(_,_,danois,the,_,_),Maisons),
member(maison(A,blanche,_,_,_,_),Maisons),
member(maison(B,verte,_,cafe,_,_),Maisons),
a_droite(A,B),
member(maison(_,_,_,_,pallmall,oiseaux),Maisons),
member(maison(_,jaune,_,_,dunhill,_),Maisons),
member(maison(3,_,_,lait,_,_),Maisons),
member(maison(1,_,norvegien,_,_,_),Maisons),
member(maison(N,_,_,_,_,chat),Maisons),
member(maison(M,_,_,_,blend,_),Maisons),
voisin_de(N, M),
member(maison(X,_,_,_,dunhill,_),Maisons),
member(maison(Y,_,_,_,_,cheval),Maisons),
voisin_de(X,Y),
member(maison(_,_,_,biere,bluemaster,_),Maisons),
member(maison(_,_,allemand,_,prince,_),Maisons),
member(maison(C,_,norvegien,_,_,_),Maisons),
member(maison(D,bleue,_,_,_,_),Maisons),
voisin_de(C,D),
member(maison(U,_,_,_,blend,_),Maisons),
member(maison(V,_,_,eau,_,_),Maisons),
voisin_de(U,V),
member(maison(_,_,_,_,_,poisson),Maisons).

the_fishman(X) :-
    resoudre(Q), member(maison(_,_,X,_,_,poisson), Q).
