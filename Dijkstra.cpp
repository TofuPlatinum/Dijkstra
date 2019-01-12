//
// Created by Fakehex on 12/01/2019.
//

#include "Dijkstra.h"


template <class C> map<Sommet<C>,list<Sommet<C>>> Dijkstra<C>::plus_court_chemin(Graphe<C>& graph,Sommet<C>& source){

    vector<Sommet<C>> sommets_Traiter;
    vector<Sommet<C>> sommets_non_Traiter;
    map<Sommet<C>,list<Sommet<C>>> dij;

    sommets_non_Traiter.push_back(source);
    int n = 0;

    while(sommets_non_Traiter.size() != 0 ) {
        n++;
        Sommet<C> sommet_Actuel = Sommet_plus_petite_distance(sommets_non_Traiter);
        int dist_correct = sommet_Actuel.distance;
        list<Sommet<C>> list_correct = sommet_Actuel.list_plus_court_chemin;
        sommet_Actuel = find_in_vector(graph.sommets,sommet_Actuel);
        sommet_Actuel.distance = dist_correct;
        sommet_Actuel.list_plus_court_chemin = list_correct;

        if(sommet_Actuel.val == source.val){
            sommet_Actuel.distance = 0;
        }
        vector<Sommet<char>>::iterator it;

        for(it = sommets_non_Traiter.begin();it != sommets_non_Traiter.end() ; it++ ){

            if(*it == sommet_Actuel){
                sommets_non_Traiter.erase(it);

                break;
            }

        }

        map<Sommet<char>, int>::iterator p;

        for (p = sommet_Actuel.listAdj.begin(); p != sommet_Actuel.listAdj.end(); p++) {

             Sommet<C> sommet_Adj = p->first;
             int poids_arete = p->second;

             if(is_in_vector(sommets_Traiter,sommet_Adj)) {
                //do nothing

             }else{


                 list<Sommet<C>> plus_court_chemin = calcule_distance_minimal(sommet_Adj,poids_arete,sommet_Actuel);

                 sommets_non_Traiter.push_back(sommet_Adj);

                 if(plus_court_chemin.size() == 0){
                     //do nothing
                     cout << "plus court chemin ERREUR : " << sommet_Actuel.val << endl;
                 }else{

                     dij.insert(pair<Sommet<C>,list<Sommet<C>>>(sommet_Actuel,plus_court_chemin));
                    cout << "insertion dans dij pour : " << sommet_Actuel.val << endl;

                 }
             }
        }
        sommets_Traiter.push_back(sommet_Actuel);

    }

    return dij;

}
template <class C> Sommet<C> Dijkstra<C>::Sommet_plus_petite_distance(vector<Sommet<C>>& sommets_non_Traiter){
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
template <class C> list<Sommet<C>> Dijkstra<C>::calcule_distance_minimal(Sommet<C>& sommet_adj,int poids_arete,Sommet<C>& sommet_actuel){

    int source_distance = sommet_actuel.distance;
    cout << "distance actuel de la source pour " << sommet_actuel.val << " : " << source_distance << endl;
    cout << source_distance + poids_arete << endl;
    list<Sommet<C>> plus_court_chemin;
    if((source_distance + poids_arete) < sommet_adj.distance ){
        sommet_adj.distance = source_distance + poids_arete;
        sommet_adj.list_plus_court_chemin.push_back(sommet_actuel);
        //graph.setDistance(sommet_adj, source_distance+poids_arete);
        plus_court_chemin = sommet_actuel.getPlusCourtChemin();


        return plus_court_chemin;
    }
    list<Sommet<C>> listVide;
    return listVide;
}
template <class C> bool Dijkstra<C>::is_in_vector(vector<Sommet<C>> sommets, Sommet<C> s){
    vector<Sommet<char>>::iterator it;
    for(it = sommets.begin(); it != sommets.end(); it++){
        if(*it == s){
            return true;
        }
    }
    return false;
}
template <class C> Sommet<C>& Dijkstra<C>::find_in_vector(vector<Sommet<C>>& sommets, Sommet<C>& s){
    vector<Sommet<char>>::iterator it;
    for(it = sommets.begin(); it != sommets.end(); it++){
        if(*it == s){
            return *it;
        }
    }
}