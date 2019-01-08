//
// Created by hadji on 08/01/19.
//

#include "Sommet.h"
#include <map>
#include <iostream>

using namespace std;
template <class C> map<Sommet<C>,int> Sommet<C>::getMap() const{
    return this->listAdj;
}
template <class C> Sommet<C>::Sommet(C v){
    val = v;
}
template <class C> void Sommet<C>::ajout(Sommet s, int i){
    s.getMap().insert(s,i);
}
template <class C> void Sommet<C>::ajouterAdj(Sommet s, int i){
    ajout(s,i);
}
template <class C> void Sommet<C>::afficher(){
    cout << listAdj << endl;
}
ostream& operator << (ostream &os, const Sommet<char> &s){
    os << s.val ;
    return os;
}

ostream & operator <<( std::ostream &os,const std::map<Sommet<char>,int> &m ){
    for (const auto &p : m){
        os << p.first << ": " << p.second;
        os << std::endl;
    }

    return os;
}