//
// Created by hadji on 08/01/19.
//

#ifndef DIJKSTRA_SOMMET_H
#define DIJKSTRA_SOMMET_H

#include <map>

template < Classe C > class Sommet {
private
    C val;
    map <C,int> listadj;
public:
    void ajouterAdj();
    Sommet(C);

};


#endif //DIJKSTRA_SOMMET_H
