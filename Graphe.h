//
// Created by hadji on 08/01/19.
//

#ifndef DIJKSTRA_GRAPHE_H
#define DIJKSTRA_GRAPHE_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

template < class C > class Graphe {
public:
    vector <Sommet<C>> sommets;
    Graphe();
    //void ajouterArete(Sommet,Sommet,int);
    //void afficher();
    //ostream& operator << (ostream&, Graphe g);
    void ajouterSommet(Sommet<C>);

};


#endif //DIJKSTRA_GRAPHE_H
