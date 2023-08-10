#include <iostream>

using namespace std;
template <typename T>
class PileTableau {
        int sp; // l’indice du sommet de pile
        int max; // nombre maximun d’éléments
        T* elements; // tableau générique d’éléments de type T
    public:
        PileTableau(int n = 100);
        ~PileTableau();
        PileTableau(const PileTableau&);
        PileTableau<T>& operator=(const PileTableau<T>&);
        // méthodes (classiques) génériques de manipulation de la pile
        bool estVide();
        void empiler(const T& x);
        void depiler();
        const T& sommet();
        int taille();
        friend ostream& operator<<(ostream & os, const PileTableau<T>& p){
            for(int i =0;i<p.sp;i++){
                os << p.elements[i]<< " ";
            }
            return os;
        }
};
template <class T>
PileTableau<T>::PileTableau(int n){
    max=n;
    elements=new T[max];
    sp=0;
}
template <class T>
PileTableau<T>::~PileTableau(){
    max=0;
    delete elements;
    sp=0;
}
template <class T>
PileTableau<T>& PileTableau<T>::operator=(const PileTableau<T> &s){
    if(this!=s){
        max=s->max;
        sp=s->sp;
        delete elements;
        elements =new T[max];
        for(int i=0;i<sp;i++)
            elements[i]=s->elements[i];
    }
    return *this;
}
template <class T>
PileTableau<T>::PileTableau(const PileTableau<T> &s){
        max=s->max;
        sp=s->sp;
        elements =new T[max];
        for(int i=0;i<sp;i++)
            elements[i]=s->elements[i];
}
template <class T>
bool PileTableau<T>::estVide(){
    if(sp==0)
        return true;
    return false ;
}
template <class T>
void PileTableau<T>::empiler(const T&x){
    if(sp<max)
        this->elements[sp++]=x;
}
template<class T>
const T& PileTableau<T>::sommet(){
    return elements[sp];
}

template <class T>
int PileTableau<T>::taille(){
    return max;
}
int main()
{
    PileTableau<int> T(100);
    T.empiler(1);
    T.empiler(2);
    T.empiler(3);
    T.empiler(4);
    cout << T;
    return 0;
}
