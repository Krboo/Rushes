femme(F) :- member(F, [anne,betty,lisa,sylvie,eve,julie,valerie]).
homme(H) :- member(H, [marc,luc,jean,jules,leon,loic,gerard,jacques,herve,paul]).

mari_de(marc,anne). mari_de(jules,lisa). mari_de(leon,sylvie). mari_de(loic,eve). mari_de(paul,julie). mari_de(luc,betty).
femme_de(X, Y) :- mari_de(Y, X).

enfant_de(A,B) :- member(A,[jean,jules,leon]) , member(B,[marc,anne]).
enfant_de(A,B) :- member(A,[lisa,loic,gerard]) , member(B,[luc,betty]).
enfant_de(jacques,B) :- member(B,[jules,lisa]).
enfant_de(A,B) :- member(A,[herve,julie]) , member(B,[leon,sylvie]).
enfant_de(A,B) :- member(A,[paul,valerie]) , member(B,[loic,eve]).

beaupere_de(X, Y) :- femme_de(Y,Z), enfant_de(Z,X), homme(X).
beaupere_de(X,Y) :- mari_de(Y,Z), enfant_de(Z,X), homme(X).
bellemere_de(X, Y) :- femme_de(X, Z), beaupere_de(Z, Y).

ancetre_de(C,D) :- enfant_de(D,C).
ancetre_de(C,E) :- enfant_de(E,D) , ancetre_de(C,D).