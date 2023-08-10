#include <iostream>

using namespace std;
template <class T>
class Point {
    T x;
    T y;
    public:
        Point(T, T);
        virtual ~Point() {};
        T& operator[](int);
        void deplacer(T, T);
        void afficher();
};
template <class T>
Point<T>::Point(T a,T b){
    x=a;
    y=b;
}
template <class T>
void Point<T>::deplacer(T dx,T dy){
    x+=dx;
    y+=dy;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
