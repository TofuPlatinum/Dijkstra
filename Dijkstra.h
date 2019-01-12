//
// Created by Fakehex on 12/01/2019.
//

#ifndef DIJKSTRA_DIJKSTRA_H
#define DIJKSTRA_DIJKSTRA_H


#include "Sommet.h"
#include "Graphe.h"

template < class C > class Dijkstra {
public:
    Graphe<C> plus_court_chemin(Graphe<C>,Sommet<C>);
    Sommet<C> Sommet_plus_petite_distance(vector<Sommet<C>>);
    void calcule_distance_minimal(Sommet<C>,int,Sommet<C>);
    bool find_in_vector(vector<Sommet<C>>, Sommet<C>);
};


#endif //DIJKSTRA_DIJKSTRA_H
