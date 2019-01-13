#include <iostream>
#include "Sommet.h"
#include "Graphe.h"
#include "Tas.h"


using namespace std;


int main(){

    Sommet<char> sA = Sommet<char>('A');
    Sommet<char> sB = Sommet<char>('B');
    Sommet<char> sC = Sommet<char>('C');
    Sommet<char> sD = Sommet<char>('D');
    Sommet<char> sE = Sommet<char>('E');
    Sommet<char> sF = Sommet<char>('F');


    sA.ajouterAdj(sB,10);
    sA.ajouterAdj(sC,15);

    sB.ajouterAdj(sD,12);
    sB.ajouterAdj(sF,15);

    sC.ajouterAdj(sE,10);



    sD.ajouterAdj(sE,2);
    sD.ajouterAdj(sF,1);

    sF.ajouterAdj(sE,5);

    vector<Sommet<char>> sommets;
    sommets.push_back(sA);
    sommets.push_back(sB);
    sommets.push_back(sC);
    sommets.push_back(sD);
    sommets.push_back(sE);
    sommets.push_back(sF);
    Tas<char> tas = Tas<char>(sommets);

    Graphe<char> g = Graphe<char>(tas);


    map<Sommet<char>,list<Sommet<char>>> resultat;

    resultat = g.plus_court_chemin(sA);

    /*sA.afficher();
    sB.afficher();
    sC.afficher();
    sD.afficher();
    sE.afficher();
    sF.afficher();*/

    map<Sommet<char>, list<Sommet<char>>>::iterator p;
    for (p = resultat.begin(); p != resultat.end(); p++) {
        cout << p->first.val << " plus court chemin : ";
        list<Sommet<char>>::iterator it;
        for (it = p->second.begin(); it != p->second.end(); it++) {
            cout << it->val;
        }
        cout << endl;
    }
}