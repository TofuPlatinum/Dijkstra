//
// Created by hadji on 08/01/19.
//

#ifndef DIJKSTRA_SOMMET_H
#define DIJKSTRA_SOMMET_H

#include <iostream>
#include <map>

using namespace std;
template < class C > class Sommet {

public:
    C val;
    map<Sommet<C>, int> listAdj;
    void ajout(Sommet,int);
    void ajouterAdj(Sommet,int);
    map<Sommet<C>,int> getMap() const;
    bool operator <(const Sommet&);
    //friend ostream& operator <<(ostream&, map<Sommet<C>,int> );
    //ostream& operator <<(ostream&, Sommet<C>);
    //friend bool operator <(const Sommet&, Sommet&);
    Sommet(C v);

    void detruireSommet();
    void detruireArete();
    void afficher();
};


#endif //DIJKSTRA_SOMMET_H
