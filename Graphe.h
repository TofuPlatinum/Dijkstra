//
// Created by hadji on 08/01/19.
//

#ifndef DIJKSTRA_GRAPHE_H
#define DIJKSTRA_GRAPHE_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <list>

template < class C > class Graphe {
private:
    list<C> tasdemerde;
    String type;

public:
    void ajouterSommet(Sommet s);
    void supprimerSommet(Sommet s);
    ostream& operator << (ostream &os, const Graphe &g);
    void parcoursLargeur();
    void parcoursProfondeur();
};


#endif //DIJKSTRA_GRAPHE_H
