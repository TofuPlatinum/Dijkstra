//
// Created by Fakehex on 12/01/2019.
//

#ifndef DIJKSTRA_TAS_H
#define DIJKSTRA_TAS_H

#include "Sommet.h"
#include <vector>
using namespace std;
template <class C> class Tas {
private:
    vector<Sommet<C>> tas;
    int taille;

    int gauche(int i){
        return 2 * i + 1;
    }
    int droite(int i){
        return 2 * i + 2;
    }
    void tasser(int i){
        int plus_petit_index = i;
        int gauche_ = gauche(i);
        int droite_ = droite(i);
        if(gauche_ < taille && tas[gauche_].position(tas[plus_petit_index]) < 0){
            plus_petit_index = gauche_;
        }
        if(droite_ < taille && tas[droite_].position(tas[plus_petit_index]) < 0){
            plus_petit_index = droite_;
        }
        if(i != plus_petit_index){
            echange(plus_petit_index,i);
            tasser(plus_petit_index);
        }
    }
    void echange(int i, int j){
        Sommet<C> n = tas[i];
        tas[i] = tas[j];
        tas[j] = n;
    }
public:
    Tas(vector<Sommet<C>>& vec){
        tas = vec;
        taille = vec.size();
    }
    Tas(){
        tas = vector<Sommet<C>>();
        taille=0;
    }
    int size(){
        return taille;
    }
    void afficher(){
        vector<Sommet<char>> :: iterator p;
        for(p = tas.begin(); p != tas.end(); p++){
            cout << p->val << " --> " ;
            map<Sommet<char>,int> :: iterator it;

            for(it = p->listAdj.begin(); it != p->listAdj.end(); it++){
                    cout << it->first.val << " " ;
            }
            cout << endl;
        }
    }
    void add(Sommet<C> valeur){
        tas.push_back(valeur);
        taille++;
        initialisation();
    }
    Sommet<C> extract_min(){
        Sommet<C> n = tas.front();
        echange(0,taille - 1);
        taille--;
        tasser(0);
        return n;
    }
    Sommet<C> extract(Sommet<C> s){
        vector<Sommet<char>>::iterator it;
        for(it = tas.begin(); it != tas.end(); it++){
            if(*it == s){
                Sommet<C> n =  *it;
                tas.erase(it);
                //taille--;
                initialisation();
                return n;
            }
        }
    }
    Sommet<C> find(Sommet<C> s){
        vector<Sommet<char>>::iterator it;
        for(it = tas.begin(); it != tas.end(); it++){
            if(*it == s){
                Sommet<C> n =  *it;
                return n;
            }
        }
    }
    bool contains(Sommet<C> s){
        vector<Sommet<char>>::iterator it;
        for(it = tas.begin(); it != tas.end(); it++){
            if(*it == s){
                return true;
            }
        }
        return false;
    }

    void initialisation(){
        for(int i = taille / 2 - 1; i >= 0; i--){
            tasser(0);
        }
    }


};


#endif //DIJKSTRA_TAS_H
