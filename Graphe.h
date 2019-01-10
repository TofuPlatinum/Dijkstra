//
// Created by hadji on 08/01/19.
//

#ifndef DIJKSTRA_GRAPHE_H
#define DIJKSTRA_GRAPHE_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <list>

template < Class C > class Graphe {
public:
    vector <Sommet<C>> sommets;
    void ajouterArete(Sommet s,Sommet s2, int poids);
    void afficher();
    //ostream& operator << (ostream&, Graphe g);
    void ajouterSommet(Sommet s);

};


#endif //DIJKSTRA_GRAPHE_H
