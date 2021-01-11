#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
//Definition of function template palindrome starts here
template<class T>
bool palindrom(vector<T> &v){//Template function to check if vector is palindrome
    bool f=true;
    typename vector<T>::iterator i;
    typename vector<T>::reverse_iterator id;
    for(i=v.begin(),id=v.rbegin();i!=v.begin()+v.size()/2;i++,id++){
        if(*i!=*id){
            f=false;
        }
    }
    return f;
}//end of function template here
int main(){
    int size;//size of the array
    int *a;//dynamic int array
    vector<int> v;//int vector
    cout<<"Enter a size for the vector:"; cin>>size;
    a = new int[size];//allocate new space
    cout<<"Enter the elements of the vector:"<<endl;
    for(int i=0;i<size;i++){
        cout<<"El ["<<i<<"]=";
        cin>>a[i];//initialize the array
    }
    v.insert(v.begin(),a,a+size);
    if(palindrom(v)){//if vector is palindrome print
        cout<<"Vektorot e palindrom"<<endl;
    }
    else{
        cout<<"Vektorot ne e palindrom"<<endl;
    }
    delete[]a;//free memory
return 0;
}
