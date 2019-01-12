//
// Created by hadji on 08/01/19.
//

#ifndef DIJKSTRA_SOMMET_H
#define DIJKSTRA_SOMMET_H

#include <iostream>
#include <map>
#include <list>

using namespace std;
template < class C > class Sommet {

public:
    C val;
    map<Sommet<C>, int> listAdj;
    int distance;
    list<Sommet<C>> list_plus_court_chemin;

    Sommet(C v);
    Sommet();
    void ajout(Sommet&,int);
    void ajouterAdj(Sommet&,int);
    map<Sommet<C>,int> getMap() const;
    list<Sommet<C>> getPlusCourtChemin() const;
    bool operator <(const Sommet&);
    bool operator ==(const Sommet&);
    //friend ostream& operator <<(ostream&, map<Sommet<C>,int> );
    //ostream& operator <<(ostream&, Sommet<C>);
    //friend bool operator <(const Sommet&, Sommet&);

    void detruireSommet();
    void detruireArete();
    void afficher();
    void afficher_list();
};


#endif //DIJKSTRA_SOMMET_H
