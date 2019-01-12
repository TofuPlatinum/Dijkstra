//
// Created by Fakehex on 12/01/2019.
//

#include "Dijkstra.h"


template <class C> Graphe<C> Dijkstra<C>::plus_court_chemin(Graphe<C> graph,Sommet<C> source){
    source.distance = 0;

    vector<Sommet<C>> sommets_Traiter;
    vector<Sommet<C>> sommets_non_Traiter;

    sommets_non_Traiter.push_back(source);

    while(sommets_non_Traiter.size() != 0 ) {
        Sommet<C> sommet_Actuel = Sommet_plus_petite_distance(sommets_non_Traiter);
        sommets_non_Traiter.erase(sommet_Actuel);
        map<Sommet<char>, int>::iterator p;
        for (p = sommet_Actuel.listAdj.begin(); p != sommet_Actuel.listAdj.end(); p++) {
             Sommet<C> sommet_Adj = p->first;
             int poids_arete = p->second;
             if(std::find(sommets_Traiter.begin(), sommets_Traiter.end(), sommet_Adj) != sommets_Traiter.end()) {
                //do nothing
             }else{
                 calcule_distance_minimal(sommet_Adj,poids_arete,sommet_Actuel);
                 sommets_non_Traiter.push_back(sommet_Adj);
             }
        }
        sommets_Traiter.push_back(sommet_Actuel);
    }

    return graph;

}
template <class C> Sommet<C> Dijkstra<C>::Sommet_plus_petite_distance(vector<Sommet<C>> sommets_non_Traiter){
    Sommet<C> sommet_optimal;
    int plus_petite_distance = 10000;
    vector<Sommet<char>>::iterator p;
    for (p = sommets_non_Traiter.begin(); p != sommets_non_Traiter.end(); p++) {
       int distance_du_sommet = p->distance;
       if(distance_du_sommet < plus_petite_distance){
           plus_petite_distance = distance_du_sommet;
           sommet_optimal = *p;
       }
    }
    return sommet_optimal;
}
template <class C> void Dijkstra<C>::calcule_distance_minimal(Sommet<C> sommet_adj,int poids_arete,Sommet<C> source){
    int source_distance = source.distance;
    if(source_distance + poids_arete < sommet_adj.distance ){
        sommet_adj.distance = source_distance + poids_arete;
        list<Sommet<C>> plus_court_chemin = list<Sommet<C>>(source.getPlusCourtChemin());
        plus_court_chemin.push_back(source);
        sommet_adj.list_plus_court_chemin = plus_court_chemin;
    }
}