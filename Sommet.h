//
// Created by hadji on 08/01/19.
//

#ifndef DIJKSTRA_SOMMET_H
#define DIJKSTRA_SOMMET_H

#include <iostream>
#include <map>
#include <list>
#include <iterator>
#include <limits>

using namespace std;
template < class C > class Sommet {

public:
    C val;
    map<Sommet<C>, int> listAdj;
    int distance;
    list<Sommet<C>> list_plus_court_chemin;

    Sommet(C v){
        val = v;
        distance = std::numeric_limits<int>::max();;
    }
    Sommet(){}
    map<Sommet<C>,int> getMap() const{
        return listAdj;
    }
    list<Sommet<C>> getPlusCourtChemin() const{
        return list_plus_court_chemin;
    }

    void ajout(Sommet& s, int i){
//s.getMap().insert(s,i);
        s.listAdj.insert(pair<Sommet<C>,int>(*this , i));
        this->listAdj.insert(pair<Sommet<C>,int>(s,i));
    }

    void ajouterAdj(Sommet& s, int i) {
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

    void afficher() {
        map<Sommet<char>, int>::iterator p;
        cout << val << "  -> \n";
        for (p = listAdj.begin(); p != listAdj.end(); p++) {
            cout << p->first.val << ": " << p->second;
            cout << std::endl;
        }
    }
     void afficher_list() {
        list<Sommet<char>>::iterator p;
        for (p = list_plus_court_chemin.begin(); p != list_plus_court_chemin.end(); p++) {
            cout << p->val;
            cout << std::endl;
        }
    }
    friend ostream& operator << (ostream &os,const Sommet<char> &s){
        os << s.val ;
        return os;
    }

     bool operator < (const Sommet<C> &s2) {
        if (this->val > s2->val) {
            return true;
        }
        return false;
    }
     bool operator == (const Sommet<C> &s2) {
        if (this->val == s2.val) {
            return true;
        }
        return false;
    }
    friend bool operator < (const Sommet<char> &s, const Sommet<char> &s2){
        if(s.val > s2.val ) {
            return true;
        }
        return false;
    }
    int position(Sommet n){
        if(distance > n.distance){
            return 1;
        }else if (distance > n.distance){
            return -1;
        }else {
            return 0;
        }
    }
    void detruireSommet();
    void detruireArete();
};


#endif //DIJKSTRA_SOMMET_H
