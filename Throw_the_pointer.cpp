#include <iostream>
using namespace std;
#include <exception>
class Test{//Test class
public:
    Test(){//test constructor
        cout<<"Constructing test"<<endl;
    }
    ~Test(){//Destructor that is never called
        cout<<"Destroying test"<<endl;
    }
};//end of test


//definition of main starts here
int main(){
    try{
        Test * p= new Test();//allocate new test
        throw *p;//throw pointer
    }
    catch(Test &p){//catch the exception
        cout<<"Bad pointer throw"<<endl;
    }
return 0;
}//end of main
