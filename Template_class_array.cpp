#include <iostream>
using namespace std;
//definition of class Array starts here
template<class T>
class Array{
private:
    T * ptr;//dynamic allocated array of T type
    int size;//size of the array
public:
    Array(){//default constructor
    size =0;
    ptr=new T[0];
    }
    const int getSize()const{return size;}
    void setSize(int a){size=(a>0)?a:0;}
    friend istream & operator >>(istream &input, Array &a){//Overloaded operator >> for array
        cout<<"Vnesi golemina: ";
        input>>a.size;
        cout<<endl<<"Vnesi gi elementite"<<endl;
        a.ptr=new T[a.size];
        for(int i=0;i<a.size;i++){
            cout<<"ptr["<<i<<"]=";
            cin>>a.ptr[i];
            cout<<endl;
        }
        return input;
    }//end of operator >>
    friend ostream & operator <<(ostream &output,Array &a){//Overloaded operator << for Array
        output<<"Nizata ima golemina "<<a.size<<" Nejzinite elementi se"<<endl;
        for(int i=0;i<a.size;i++){
            output<<"ptr["<<i<<"]= "<<a.ptr[i]<<endl;
        }
        return output;
    }//End of operator << for array
};
int main(){//Test for class array
    Array<float>f;//Create new empty float array
    Array<int>i;//Create new empty int array
    cout<<"Vnesi float niza"<<endl;
    cin>>f;
    cout<<f;
    cout<<"Vnesi int niza"<<endl;
    cin>>i;
    cout<<i;
return 0;
}
