#include <iostream>
#include <string>
using namespace std;
template<class T>
T Min(T a,T b){
    return a<b ? a:b;
}
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
int main() {
    rectangle r1(5,4.1),r2(8.2,3.4);
    cout << Min (r1 ,r2) << endl;
    return 0;
}
