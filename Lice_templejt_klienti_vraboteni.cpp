#include <iostream>
#include <cstring>
using namespace std;

template<class T>//template for person
class Person{
private:
    char * name;// name of the person
    unsigned long id;// Id of the person
    unsigned int age;// age of the person
    char * adress;// adress of the person
    T code;//code of the person
public:
    Person(){}
    Person(char * name, int id, int age, char*adress, T code){//Constructor with parameters
        setName(name);
        setID(id);
        setAge(age);
        setAdress(adress);
        setCode(code);
    }//end of constructor
    ~Person(){//destructor
        delete [] name;//dealocate name
        delete [] adress;//dealocate adress
    }
    void setName(char * i){
        name = new char[strlen(i)+1];
        strcpy(name,i);
    }
    void setAdress(const char *a){
        adress=new char[strlen(a)+1];
        strcpy(adress,a);
    }
    void setID(unsigned long i){id=i;}
    void setAge(unsigned int a){age=a;}
    void setCode(T code){this->code=code;}
    char * getName()const{return name;}
    const char * getAdress()const{return adress;}
    const unsigned long getID()const{return id;}
    const unsigned int getAge()const{return age;}
    const T getCode()const{return code;}
    friend ostream & operator<<(ostream & output, const Person &p){//overload operator <<
        output<<"Ime: "<<p.name<<" Maticen: "<<p.id<<" Vozrast: "<<p.age<<" Adresa: "<<p.adress<<" Kod: "<<p.code<<endl;
        return output;
    }
    Person & operator =(const Person &right){//operator = for person
        name = new char[strlen(right.getName())+1];
        strcpy(name,right.getName());
        setAdress(right.getAdress());
        setID(right.getID());
        setAge(right.getAge());
        setCode(right.getCode());
        return *this;
    }//end of operator =
};
template<class T>//template print function for array
void pecatiPole(T*ptr, const int &n){
    for(int i=0;i<n;i++){
        cout<<ptr[i];
    }
}//end of print function

int main(){
    int choice,counterV=0,counterK=0;//choice for the meny counter for enements for vraboten and kliend
    Person<int> Vraboteni[10];//array of vraboteni
    Person<char *> Klienti[10];//array of klienti
    char name[20],adress[20],CK[20];//variables for name adress and code for klient
    int id,age,CV;//variables for id age and code for vraboten
    do{
    cout<<"1-Vnesi podatoci za vraboten"<<endl<<"2-Vnesi podatoci za klient"<<endl<<"3-Pecati podatoci za vraboten";
    cout<<endl<<"4-Pecati podatoci za klient"<<endl<<"5-Kraj"<<endl;
    cin>>choice;
    cout<<endl;
    if(choice==1){//if choesn 1 enter new vraboten
        cout<<"Vnesi ime: ";cin>>name;
        cout<<endl<<"Vnesi adresa: ";cin>>adress;
        cout<<endl<<"Vnesi id: ";cin>>id;
        cout<<endl<<"Vnesi godini: ";cin>>age;
        cout<<endl<<"Vnesi broen kod: ";cin>>CV;
        Vraboteni[counterV++]=Person<int>(name,id,age,adress,CV);
    }
    else if(choice==2){//if chosen 2 enter new klient
        cout<<"Vnesi ime: ";cin>>name;
        cout<<endl<<"Vnesi adresa: ";cin>>adress;
        cout<<endl<<"Vnesi id: ";cin>>id;
        cout<<endl<<"Vnesi godini: ";cin>>age;
        cout<<endl<<"Vnesi string kod: ";cin>>CK;
        Klienti[counterK++]=Person<char *>(name,id,age,adress,CK);
    }
    else if(choice==3){//if chosen 3 print vraboten
        pecatiPole(Vraboteni, counterV);
    }
    else if(choice==4){//if chosen 4 print klient
        pecatiPole(Klienti,counterK);
    }
    }while(choice!=5);



return 0;
}



