#include<iostream>
using namespace std;

template<typename T>
int printArray(T * ptr, const int &n, int lowSubscript, int highSubscript){//Overiding printArray
    if(highSubscript>n||highSubscript<0||lowSubscript<0||lowSubscript>n)//check if hi and lo are in the range of the indexes
        return 0;
    else{
            int counter=0;
        for(int i=lowSubscript-1;i<highSubscript;i++,counter++){
            cout<<ptr[i]<<" ";
        }
        return counter;//return how many numbers have been printed
    }
}
int main(){
    float f[10];
    char c[10];
    int l,h;
    int r;
    cout<<"Vnesi 10 float vrednosti"<<endl;
    for(int i=0;i<10;i++){
        cin>>f[i];//initialize float array
    }
    cout<<endl<<"Vnesi od koja do koja da se isprintaat"<<endl;cin>>l>>h;
    if((r=printArray(f,10,l,h))==0){//teest printArray function for float
        cout<<"Nevalidni granici"<<endl;
    }
    else{
        cout<<endl<<"Po printanjeto na nizata ispecateni se "<<r<<" elementi"<<endl;
    }
    cout<<"Vnesi 10 char vrednosti"<<endl;
    for(int i=0;i<10;i++){
        cin>>c[i];//initialize char array
    }
    cout<<endl<<"Vnesi od koja do koja da se isprintaat"<<endl;cin>>l>>h;
    if((r=printArray(c,10,l,h))==1){//test printArray for char
        cout<<"Nevalidni granici"<<endl;
    }
    else{
        cout<<endl<<"Po printanjeto na nizata ispecateni se "<<r<<" elementi"<<endl;
    }
    return 0;
}
