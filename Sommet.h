//
// Created by hadji on 08/01/19.
//

#ifndef DIJKSTRA_SOMMET_H
#define DIJKSTRA_SOMMET_H

#include <map>
using namespace std;

template <class C> class Sommet {
public:
    C val;
    map<Sommet, int> listAdj;
    void ajout(Sommet,int);
    void ajouterAdj(Sommet,int);
    map<Sommet,int> getMap() const;
    void ajouterArete();
    void detruireSommet();
    void detruiteArete();
    void afficher();
    Sommet(C);



};

#endif //DIJKSTRA_SOMMET_H
