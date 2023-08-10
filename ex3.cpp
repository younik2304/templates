#include <iostream>
using namespace std;
class rectangle{
    double longueur,largeur;
public:
    rectangle(){
        longueur=largeur=0;
    }
    rectangle(double lo,double lr){
        longueur=lo;
        largeur=lr;
    }
    double surface() const{
        return longueur*largeur;
    }
    bool operator<(const rectangle &c){
        return surface() < c.surface();
    }
    friend ostream& operator<<(ostream& os, const rectangle& r){
        os<<r.surface();
        return os;
    }
};
template <class T>
struct Noeud {
    T info;
    Noeud* suivant;
};
template <class T>
class Liste {
Noeud<T>* tete;
public:
Liste() { tete = 0; };
~Liste() { eraseListe(); };
void push(T data);
bool empty() { return tete == 0; }
void eraseListe();
void pop();
void affiche();
};
template <class T>
void Liste<T>::push(T data) {
    Noeud<T>* nouveauNoeud = new Noeud<T>;
    nouveauNoeud->info = data;
    nouveauNoeud->suivant = tete;
    tete = nouveauNoeud;
}

template <class T>
void Liste<T>::eraseListe() {
    Noeud<T>* current = tete;
    while (current != nullptr) {
        Noeud<T>* next = current->suivant;
        delete current;
        current = next;
    }
    tete = nullptr;
}

template <class T>
void Liste<T>::pop() {
    if (tete != nullptr) {
        Noeud<T>* temp = tete;
        tete = tete->suivant;
        delete temp;
    }
}

template <class T>
void Liste<T>::affiche() {
    Noeud<T>* current = tete;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->suivant;
    }
    cout << std::endl;
}

int main()
{
    Liste<rectangle>a;

    rectangle d(3,5),c;
    a.push(d);
    a.affiche();

    return 0;
}
