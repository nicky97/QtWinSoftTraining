#include <iostream>
using namespace std;
#include <cstring>

template<class T>
class Mnozestvo{
private:
    T*ptr;//dynamic pointer to the container
    static int counter;//counter of the elements
public:
    const int getCounter()const{return counter;}
    Mnozestvo(){//constructor
        ptr=new T[1];
    }
    void add(T r){//add element function
        if(counter==0){//if no elements add the first
            ptr[counter++]=r;
        }
        else{
            for(int i=0;i<counter;i++){
                if(ptr[i]==r)//check if element already exist
                    return;
            }
            T *tmp=new T[counter+1];//allocate new array to store new element
            for(int i=0;i<counter;i++){
                tmp[i]=ptr[i];//copy the elements of the old array to the new
            }
            tmp[counter++]=r;//add the last element
            delete[]ptr;//delete the previous array
            ptr=tmp;//set the ptr to the adress of the new array
        }
    }
    void print()const{//print function
        if(counter==0){
            cout<<"Nema elementi za prikaz"<<endl;
            return;
        }
        cout<<"Elementite se: "<<endl;
        for(int i=0;i<counter;i++){
            cout<<ptr[i]<<endl;
        }
    }//end of print function
    void MAX()const{//Find max element function
        if(counter==0){
            cout<<"Nema elementi"<<endl;
        }
        T MAX=ptr[0];//set the first elemnt to be the biggest
        for(int i=1;i<counter;i++){
            if(ptr[i]>MAX){//if the current elemnt is bigger than the prvious
                MAX=ptr[i];//make the current element the max
            }
        }
        cout<<"Najgolemiot element e "<<MAX;
    }

};

template<>
void Mnozestvo<char*>::MAX()const{//specialization to find max element for *char
    if(counter==0){
        cout<<"Nema elementi"<<endl;
        return;
    }
    char*p=ptr[0];
    for(int i=0;i<counter;i++){
        if(strcmp(ptr[i],p)==1){
            p=ptr[i];
        }
    }
    cout<<"Najgolemiot element e "<<*p;


//end of specialization
template<class T> int Mnozestvo<T>::counter=0;

int main(){//test templejt
    int choice,inA;
    float inB;
    char *inC=new char[1];
    Mnozestvo<int> A;
    Mnozestvo<float>B;
    Mnozestvo<char*>C;
    do{
        cout<<"1-Dodaj element vo A"<<endl<<"2-Dodaj element vo B"<<endl<<"3-Dodaj element vo C"<<endl;
        cout<<"4-Prikazi go A"<<endl<<"5-Prikazi go B"<<endl<<"6-Prikazi go C"<<endl;
        cout<<"7-Prikazi gi najgolemite elementi"<<endl<<"8-Prikazi broj na elementi vo mnozestva"<<endl;
        cin>>choice;
        if(choice==1){
            cout<<"Add int element vo A"<<endl;
            cin>>inA;
            A.add(inA);
        }
        if(choice==2){
            cout<<"Add float element vo B"<<endl;
            cin>>inB;
            B.add(inB);
        }
        if(choice==3){
            cout<<"Add char element vo C"<<endl;
            cin>>inC;
            C.add(inC);
        }
        if(choice==4){
            A.print();
        }
        if(choice==5){
            B.print();
        }
        if(choice==6){
            C.print();
        }
        if(choice==7){
            A.MAX();
            cout<<endl;
            B.MAX();
            cout<<endl;
            C.MAX();
            cout<<endl;
        }
        if(choice==8){
            cout<<"A ima "<<A.getCounter()<<endl;
            cout<<"B ima "<<B.getCounter()<<endl;
            cout<<"C ima "<<C.getCounter()<<endl;
        }
    }while(choice!=9);
return 0;
}
