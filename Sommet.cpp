//
// Created by hadji on 08/01/19.
//

#include "Sommet.h"
#include <map>
#include <iostream>
#include <iterator>
using namespace std;
template <class C> map<Sommet<char>,int> Sommet<C>::getMap() const{
    return this->listAdj;
}
template <class C> Sommet<C>::Sommet(C v){
    val = v;
}
template <class C> void Sommet<C>::ajout(Sommet s, int i){
    //s.getMap().insert(s,i);
    s.listAdj.insert(pair<Sommet<C>,int>(*this , i));
    this->listAdj.insert(pair<Sommet<C>,int>(s,i));
}
template <class C> void Sommet<C>::ajouterAdj(Sommet s, int i){
    ajout(s,i);

}
template <class C> void Sommet<C>::afficher(){
    map<Sommet<char>, int>::iterator p;
    for(p = listAdj.begin(); p != listAdj.end(); p++){
        cout << p->first.val << ": " << p->second;
        cout << std::endl;
    }
}
ostream& operator << (ostream &os, const Sommet<char> &s){
    os << s.val ;
    return os;
}
template <class C> bool Sommet<C>::operator < (const Sommet<C> &s2){
    if(this->val > s2->val ) {
        return true;
    }
    return false;
}
bool operator < (const Sommet<char> &s, const Sommet<char> &s2){
    if(s.val > s2.val ) {
        return true;
    }
    return false;
}
