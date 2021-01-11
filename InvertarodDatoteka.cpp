#include <iostream>
#include<fstream>
#include<vector>
#include<exception>
#include<algorithm>
#include<numeric>
#include<iterator>
using namespace std;


//DEfinicia naklasata inventar pocnuva tuka
class Inventar{
private:
    int id,kolicina;
    float cena;
public:
    Inventar(int id,int kolicina,float cena):id(id),kolicina(kolicina),cena(cena){//constructor with parameters
    }
    friend ostream &operator <<(ostream &output, const Inventar & i){//overloaded ostream operator <<
        output<<i.getId()<<" "<<i.getKolicina()<<" "<<i.getCena()<<endl;
    }
    void setId(int x){id=x;}
    void setKolicina(int x){kolicina=x;}
    void setCena(float x){cena=x;}
    const int getId()const{return id;}
    const int getKolicina()const{return kolicina;}
    const float getCena()const{return cena;}
    friend operator +(double d, const Inventar & i){//Overloaded operator + for accumulate
        return d+i.getCena();
    }
};//end of Inventar class

//class for cant open file exception
class noFile:public runtime_error{//
public:
    noFile(const string & msg=""):runtime_error(msg){//constructor
    }
};// of class for exception
bool checkData(const Inventar & i){//predicate to check if article has price lower than 10
    return (i.getCena()<10);
}


//main starts here
int main(){
    std::ifstream in("inventar.txt");//try to open the file
    int id,kolicina;
    float cena;
    try{
    if(!in){//if file cant be opened throw exception
        throw noFile("Datotekata nemoze da se otvori");
    }
    vector<Inventar> inventar;//create vector of inventar
    while(in>>id>>kolicina>>cena){//add elements from the file in the vector
        inventar.push_back(Inventar(id,kolicina,cena));
    }
    cout<<endl<<"Vkumna cena na site artikli e: "<<accumulate(inventar.begin(), inventar.end(),0);//print the sum of the articles
    ostream_iterator<Inventar> out(cout, "\n");//Ostream iterator for Inventar
    remove_if(inventar.begin(),inventar.end(),checkData);//remove the elements that price is greater than 10
    copy(inventar.begin(),inventar.end(),out);//print the articles
    }
    catch(noFile & msg){//catch the cant open file exception
          cout<<msg.what()<<endl;
          }

return 0;
}//end of main
