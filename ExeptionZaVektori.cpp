#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
#include<stdlib.h>
#include<exception>


//Main starts here
int main(){
    vector<int> a(rand()%999+1),b(rand()%999+1);//create 2 vectors with randoms size

    try{
        if(a.size()<b.size()){//if the first vector is smaller than the second throw exception
            throw 1;
        }
        copy(a.begin(),a.end(),b.begin());//copy the second vector to the first
    }
    catch(int i){//catch  unmatched size exception
        cout<<"Not enough space in first vector"<<endl;
    }
return 0;
}
