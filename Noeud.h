//
// Created by Fakehex on 12/01/2019.
//

#ifndef DIJKSTRA_NOEUD_H
#define DIJKSTRA_NOEUD_H


template <class C> class Noeud {
private:
    Noeud<C> nD;
    Noeud<C> nG;
    C valeur;
public:
    Noeud(C val){
        valeur = val;
    }
    C getValeur(){
        return valeur;
    }
    void setNoeudDroit(Noeud<C> noeud){
        nD = noeud;
    }
    void setNoeudGauche(Noeud<C> noeud){
        nG = noeud;
    }




};


#endif //DIJKSTRA_NOEUD_H
