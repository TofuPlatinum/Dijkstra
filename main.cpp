#include <iostream>
#include "Sommet.cpp"
#include "Graphe.cpp"

using namespace std;

int main(){
    Sommet<char> s = Sommet<char>('c');
    Sommet<char> s2 = Sommet<char>('a');
    Sommet<char> s3 = Sommet<char>('b');
    s.ajouterAdj(s2,5);
    s.ajouterAdj(s2,5);
    s.ajouterAdj(s3,6);
    //Graphe<char> g = Graphe<char>();

    s.afficher();
}