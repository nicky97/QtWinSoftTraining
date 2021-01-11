#include<iostream>
#include<algorithm>
#include<string>
#include<exception>
#include<vector>
#include<iterator>
using namespace std;

class Bukva{//class char
private:
    char a;
    bool t;
public:
    Bukva(char a, bool t):a(a),t(t){}//constructor with parameters
    void setA(char x){a=x;}//setter for char
    void setT(bool x){t=x;}//setter for if char appears
    const char getA()const{return a;}//getter for char
    const bool getT()const{return t;}//getter for appearance
    friend ostream & operator<<(ostream &output, const Bukva &a){//overloaded << operator for copy algorithm
        if(a.getT()==true){
            output<<a.getA();
        }
        else{
            output<<"-";
        }
    }//end of ostream operator
    bool operator ==(const char a){//overloaded == operator
        return getA()==a;
    }
};//end of class char

//Develop runtime exception
class forbitten:public runtime_error{
public:
    forbitten(const string msg=""):runtime_error(msg){

}
};//end of exception

//function to check if the letter is correct and change its apphearance
void proverka(Bukva & b,char &a){
    if(b.getA()==a){
        b.setT(true);
    }
}//End of check function

//Main starts here
int main(){
    string zbor;//word to be entered
    int choice;
    bool won=false;//is Won var
    char a;//letter variable
    do{
       bool flag=true;
       int lives=10;//set the number of lives
       cout<<"0-EXIT||1-Start new game :";//Print menu
       cin>>choice;
       try{
       cout<<"Enter word: "; cin>>zbor;
       for(int i=0;i<zbor.size();i++){//check if all letters are valid
            if(!(islower(zbor[i]))){
                flag=false;
            }
       }//end of check for
       if(!flag){//if word is invalid throw exception
        throw forbitten("Invalid word");
       }
       }
       catch(const forbitten &f){//Catch Invalid word exception
        cout<<f.what()<<endl;
        terminate();
       }
       vector<Bukva> v;//create vector of chars

       for(int i=0;i<zbor.length();i++){
        v.push_back(Bukva(zbor[i],false));//put the chars in the vector
       }

       vector<Bukva>::iterator finder;//create iterator to navigate through the vector
       ostream_iterator<Bukva> out(cout,"");//create iterator for printing
       copy(v.begin(),v.end(),out);
       while(lives!=0&&!won){//check if player has won or run out of lives
        cout<<endl<<"Enter character:";cin>>a;//enter new letter
        finder=find(v.begin(),v.end(),a);//check if letter is present
        if(finder==v.end()){//if leter is not present decrease lives
            lives--;
        }
        else{
            finder=v.begin();//set the iterator to the beggining of the vector
            for(;finder!=v.end();finder++){//find the letter to be shown and turn it visible
                proverka(*finder,a);
            }
            bool w=true;//tmp variable to help if player has won
            for(finder=v.begin();finder!=v.end();finder++){//check if player have more letters to find
                if(finder->getT()==false){//if there are letters to find
                    w=false;//set w to not won
                }
            }
            if(w==true){//if player has won congratz the player
                won=w;
                cout<<"Congratz you have won"<<endl;
            }

        }
        if(lives==0){//if player has runned out of lives hang him
            cout<<"You have been hanged"<<endl;
        }
        else if(!won){//print the status of the word to the player along with lives
        copy(v.begin(),v.end(),out);
        cout<<" You have "<<lives<<" left";
        }
       }
    }while(choice!=0);
return 0;
}//end of main
