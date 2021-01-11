#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;

//Definiton of class Uplata
class Uplata{
public:
    int id,uplata;
    char ime[20];
    Uplata(){}//default constructor
    Uplata(char*i,int id,int uplata):id(id),uplata(uplata){//Constructor with parameters
        strcpy(ime,i);
        }

};//end of class uplata
typedef multimap<int,Uplata,less<int> > multi;//create new type of multimap for Uplata
typedef pair<int,Uplata> user;//define new type of pair
int main(){
    multi banka;
    int choice,id,id2,amount;
    char name[20];
    typedef multimap<int,Uplata>::iterator t;//create type for iterator for multimap for Uplata
    pair<t,t> a;//iterator of 2 iterators to multimap
    do{
        cout<<"1-Vnesi uplata"<<endl<<"2-Prikazi uplati"<<endl<<"3-EXIT"<<endl;
        cin>>choice;
        if(choice==1){
           cout<<"Vnesi ime: ";cin>>name;
           cout<<"Vnesi smetka: ";cin>>id;
           cout<<"Vnesi iznos: ";cin>>amount;
           cout<<"Vnesi smetna na koja treba da se uplati:";cin>>id2;
           banka.insert(user(id,Uplata(name,id,amount)));//Insert new uplata to the multiset banka

        }
        else if(choice==2){
            cout<<"Vnesi id na stedac za koj sakas da vidis uplati:";cin>>id;
            a=banka.equal_range(id);//set the first iterator to start of the id key and secont to the end of the id
            t it;//create new iterator to multimap
            for(it=a.first;it!=a.second;it++){//go through all elements with the iterator which contain the id
                cout<<"Ime:"<<it->second.ime<<" broj na smetka:"<<it->second.id<<" uplata:"<<it->second.uplata<<endl;
            }

        }

    }while(choice!=3);



return 0;
}






