//
// Created by hadji on 08/01/19.
//

#include "Sommet.h"
#include <iterator>
using namespace std;
template <class C> Sommet<C>::Sommet(C v){
    val = v;
    distance = 9999;
}
template <class C> Sommet<C>::Sommet(){}
template <class C> map<Sommet<C>,int> Sommet<C>::getMap() const{
    return listAdj;
}
template <class C> list<Sommet<C>> Sommet<C>::getPlusCourtChemin() const{
    return list_plus_court_chemin;
}

template <class C> void Sommet<C>::ajout(Sommet& s, int i){
//s.getMap().insert(s,i);
    s.listAdj.insert(pair<Sommet<C>,int>(*this , i));
    this->listAdj.insert(pair<Sommet<C>,int>(s,i));
}

template <class C> void Sommet<C>::ajouterAdj(Sommet& s, int i) {
    bool valide = true;
    if(s==*this){
        cout << "impossible d'ajouter " << s.val << " dans " << this->val << endl;
        valide = false;
    } else{
        map<Sommet<char>, int>::iterator p;
        for (p = listAdj.begin(); p != listAdj.end(); p++) {
            if(s == p->first){
                cout << "impossible d'ajouter " << s.val << " dans " << this->val << " ( Existe deja ) " << endl;
                valide = false;
            }
        }

    }
    if(valide){
        ajout(s, i);
    }

}

template <class C> void Sommet<C>::afficher() {
    map<Sommet<char>, int>::iterator p;
    cout << val << "  -> \n";
    for (p = listAdj.begin(); p != listAdj.end(); p++) {
        cout << p->first.val << ": " << p->second;
        cout << std::endl;
    }
}
template <class C> void Sommet<C>::afficher_list() {
    list<Sommet<char>>::iterator p;
    for (p = list_plus_court_chemin.begin(); p != list_plus_court_chemin.end(); p++) {
        cout << p->val;
        cout << std::endl;
    }
}
ostream& operator << (ostream &os,const Sommet<char> &s){
    os << s.val ;
    return os;
}

template <class C> bool Sommet<C>::operator < (const Sommet<C> &s2) {
    if (this->val > s2->val) {
        return true;
    }
    return false;
}
template <class C> bool Sommet<C>::operator == (const Sommet<C> &s2) {
    if (this->val == s2.val) {
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