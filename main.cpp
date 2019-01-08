#include <iostream>
#include "Sommet.h"

using namespace std;

int main(){
    Sommet<char> s = Sommet<char>('c');
    Sommet<char> s2 = Sommet<char>('a');
    std::cout << s2 << endl;
    s.ajouterAdj(s2,5);
    s.afficher();
}