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
    g = d.plus_court_chemin(g,sA);
    // erase marche bien;


    vector<Sommet<char>> vec;
    vec.push_back(sA);
    vec.push_back(sB);
    vec.push_back(sC);
    vec.push_back(sD);
    vec.push_back(sE);


   /* sA.afficher();
    sB.afficher();
    sC.afficher();
    sD.afficher(); */

    sA.afficher_list();
    sB.afficher_list();
    sC.afficher_list();
    sD.afficher_list();
    sE.afficher_list();
    sF.afficher_list();
}