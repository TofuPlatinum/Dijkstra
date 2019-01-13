//
// Created by hadji on 08/01/19.
//

#ifndef DIJKSTRA_GRAPHE_H
#define DIJKSTRA_GRAPHE_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "Tas.h"
#include "Sommet.h"

template < class C > class Graphe {
public:
    Tas <C> sommets;


   Graphe(Tas<C> s){
       sommets = s;
   }
   void afficher(){
       sommets.afficher();
   }
   void ajouterSommet(Sommet<C> &s){
       sommets.add(s);
   }
    map<Sommet<C>,list<Sommet<C>>> plus_court_chemin(Sommet<C>& source){

        Tas<C> sommets_Traiter;
        Tas<C> sommets_non_Traiter;
        map<Sommet<C>,list<Sommet<C>>> resultat;

        sommets_non_Traiter.add(source);

        while(sommets_non_Traiter.size() != 0 ) {
            Sommet<C> sommet_Actuel = sommets_non_Traiter.extract_min();

            if(sommet_Actuel.val == source.val){
                sommet_Actuel.distance = 0;
            }
            sommets_non_Traiter.extract(sommet_Actuel);

            map<Sommet<char>, int>::iterator p;

            for (p = sommet_Actuel.listAdj.begin(); p != sommet_Actuel.listAdj.end(); p++) {
                Sommet<C> sommet_Adj = sommets.find(p->first);//cherche la correspandance du sommet dans le graphe pour debug
                int poids_arete = p->second;
                if(!sommets_Traiter.contains(sommet_Adj)) {
                    list<Sommet<C>> plus_court_chemin = calcule_distance_minimal(sommet_Adj,poids_arete,sommet_Actuel);
                    sommets_non_Traiter.add(sommet_Adj);
                    if((plus_court_chemin.size() == 0 )&&!(sommet_Actuel.val == source.val) ){
                        //do nothing
                    }else{
                        resultat.insert(pair<Sommet<C>,list<Sommet<C>>>(sommet_Actuel,plus_court_chemin));
                    }
                }
            }
            sommets_Traiter.add(sommet_Actuel);
        }
        cout << "FIN DE  DIJKSTRA" << endl;
        return resultat;

    }

    list<Sommet<C>> calcule_distance_minimal(Sommet<C>& sommet_adj,int poids_arete,Sommet<C>& sommet_actuel){

        int source_distance = sommet_actuel.distance;
        cout << "distance actuel de la source pour " << sommet_actuel.val << " : " << source_distance << endl;
        list<Sommet<C>> plus_court_chemin;
        if((source_distance + poids_arete) < sommet_adj.distance ){
            sommet_adj.distance = source_distance + poids_arete;
            sommet_adj.list_plus_court_chemin.push_back(sommet_actuel);
            plus_court_chemin = sommet_actuel.getPlusCourtChemin();


            return plus_court_chemin;
        }
        list<Sommet<C>> listVide;
        return listVide;
    }

};


#endif //DIJKSTRA_GRAPHE_H
