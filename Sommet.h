//
// Created by hadji on 08/01/19.
//

#ifndef DIJKSTRA_SOMMET_H
#define DIJKSTRA_SOMMET_H

#include <iostream>
#include <map>
using namespace std;

template <class C> class Sommet {
public:
    C val;
    map<Sommet<char>, int> listAdj;
    void ajout(Sommet,int);
    void ajouterAdj(Sommet,int);
    map<Sommet<char>,int> getMap() const;
    bool operator <(const Sommet&);
    //friend ostream& operator <<(ostream&, map<Sommet<C>,int> );
   //friend bool operator <(const Sommet&, const Sommet&);
    void ajouterArete();
    void detruireSommet();
    void detruiteArete();
    void afficher();
    Sommet(C);



};

#endif //DIJKSTRA_SOMMET_H
