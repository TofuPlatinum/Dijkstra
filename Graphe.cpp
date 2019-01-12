//
// Created by hadji on 08/01/19.
//

#include "Graphe.h"

template <class C> void Graphe<C>::ajouterSommet(Sommet<C> s){
    this->sommets.push_back(s);
}
template <class C> void Graphe<C>::setDistance(Sommet<C> s,int d){
    vector<Sommet<char>>::iterator it;
    for(it = sommets.begin(); it != sommets.end(); it++){
        if(*it == s){
            cout << "erase " << it->val << endl;
            sommets.erase(it);
            break;
        }
    }
    s.distance = d;
    sommets.push_back(s);
}