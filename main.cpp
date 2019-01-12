#include <iostream>
#include "Sommet.cpp"
#include "Graphe.cpp"
#include "Dijkstra.cpp"

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

    Graphe<char> g = Graphe<char>();

    g.ajouterSommet(sA);
    g.ajouterSommet(sB);
    g.ajouterSommet(sC);
    g.ajouterSommet(sD);
    g.ajouterSommet(sE);
    g.ajouterSommet(sF);

    Dijkstra<char> d;
    map<Sommet<char>,list<Sommet<char>>> dij;
    dij = d.plus_court_chemin(g,sA);
    // erase marche bien;





    /*sA.afficher();
    sB.afficher();
    sC.afficher();
    sD.afficher();
    sE.afficher();
    sF.afficher(); */

    map<Sommet<char>, list<Sommet<char>>>::iterator p;
    for (p = dij.begin(); p != dij.end(); p++) {
        cout << p->first.val << " plus court chemin : ";
        list<Sommet<char>>::iterator it;
        for (it = p->second.begin(); it != p->second.end(); it++) {
            cout << it->val << " ";
        }
        cout << endl;
    }
}