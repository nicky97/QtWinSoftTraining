#include<iostream>
using namespace std;

class Avtomobil{//car class
private:
    bool motor;
public:
    void setMotor(bool t){
        motor=t;
    }
    const bool getMotor()const{return motor;}
};
class Garaza{//garage class
private:
    Avtomobil a;
public:
    Garaza(bool t){//Constructor
        try{
            Avtomobil(t);
            if(a.getMotor()==false){//if engine is bugged throw exception
                throw false;
            }
        }
        catch(bool & t){//catch the engine bugged exception
            cout<<"Constructor exception"<<endl;
            throw 100;//throw exception to be called in main
        }
    }
};//end of garage class


int main(){//start of main
    try{
        Garaza g(false);
    }
    catch(int i){//Catch exception thrown by constructor
        cout<<"Outer from constructor cathed in main"<<endl;
    }
return 0;
}//End of main
