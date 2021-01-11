#include<iostream>
using namespace std;
#include<string>
template<class T>
class Pole{//array template
    template<typename U>//declaration of friend function template prototype
    friend void MAX(Pole<U> &);
private:
    T data[100];//data of the array
    int nth;//current number of elements
public:
    const int getCounter()const{return nth;}
    Pole(){nth =0;}//Constructor
    void add(T d){//add function
        data[nth++]=d;
    }
};//end of array template

template<typename T>
void MAX(Pole<T> & pole){//function template to find maximum of given field of array
    T tmp=pole.data[0];
    for(int i=1;i<pole.nth;i++){
        if(pole.data[i]>tmp){
            tmp=pole.data[i];
        }
    }
    cout<<"Maksimalniot element e:"<<tmp<<endl;//print the max element
}//end of function max template

template<>
void MAX(Pole<string> & pole){//speciation of the MAX function for string elements
    string tmp=pole.data[0];
    for(int i=1;i<pole.nth;i++){
        if(tmp.compare(pole.data[i])==-1){
            tmp=pole.data[i];
        }
    }
    cout<<"Maksimalniot element e:"<<tmp<<endl;
}//end of specialization

int main(){//main starts here
    Pole<char> arrayc;//create empty arras of chars
    char c;
    Pole<string> arrays;//create empty array of string
    string s;
    Pole<int> arrayi;//create empty array of integers
    int a;
    cout<<"Enter 5 char elements"<<endl;
    for(int i=0;i<5;i++){//input the elements of the char array
        cin>>c;
        arrayc.add(c);
    }
    cout<<"Enter 5 string elements"<<endl;
    for(int i=0;i<5;i++){//input the elements of the string array
        cin>>s;
        arrays.add(s);
    }
    cout<<"Enter 5 int elements"<<endl;
    for(int i=0;i<5;i++){//input the elements of the int array
        cin>>a;
        arrayi.add(a);
    }
    MAX(arrayc);//call max funtions to print the max element
    MAX(arrays);
    MAX(arrayi);
return 0;
}//end of main
