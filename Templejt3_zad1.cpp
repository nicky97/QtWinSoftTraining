#include<iostream>
using namespace std;
#include<conio.h>

template<typename T>//Definition of template class Zapis
class Zapis{
template<typename U>
friend void Kontroler(Zapis<U> &);//declare friend template function
T x,y,z;//Records a,b,c
public:
    Zapis(T a, T b, T c):x(a),y(b),z(c){//constructor for zapis
    }
};
template<typename T>
void Kontroler(Zapis<T> &z){//Template function
    if((z.x+z.y+z.z)>10000)
        cout<<"Zbirot na vrednosti na zapisot se pogolemi od 10000"<<endl;
    else{
        cout<<"zbirot na vrednosti na zapisot se pomali od 10000"<<endl;
    }
}
int main(){
    Zapis<float> z(100,14.42,9990.142);//constructor for float arguments
    Kontroler<float>(z);//test the template function for float
    Zapis<int>i(10,14,5225);//constructor for in arguments
    Kontroler<int>(i);//test the template function for int
return 0;
}
