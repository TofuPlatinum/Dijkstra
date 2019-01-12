//
// Created by hadji on 08/01/19.
//

#include "Graphe.h"

template <class C> void Graphe<C>::ajouterSommet(Sommet<C> s){
    this->sommets.push_back(s);
}