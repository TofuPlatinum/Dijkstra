#include "Sommet.cpp"

using namespace std;

int main(){
    Sommet<char> s = Sommet<char>('c');
    Sommet<char> s2 = Sommet<char>('a');
    s.ajouterAdj(s2,5);
    s.afficher();
}