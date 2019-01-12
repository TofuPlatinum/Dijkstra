//
// Created by Fakehex on 12/01/2019.
//

#ifndef DIJKSTRA_TAS_H
#define DIJKSTRA_TAS_H

#include "Noeud.h"

template <class C> class Tas {
    Noeud<C> pere;

    C getMinimum(){
        return pere.getValeur();
    }
    void ajouterElement(C){

    }
    C get(C valeur){

    }
    void supprimer(C valeur){

    }

};


#endif //DIJKSTRA_TAS_H
