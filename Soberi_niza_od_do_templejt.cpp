#include<iostream>
using namespace std;

template <typename T>//Template for function that sums the elements of array or type T
T Soberi(T *ptr,int l=T(), int h=T(), T sum=T()){
    for(;l<h;l++){
        sum+=ptr[l];
    }
    return sum;//
}//end of function
int main(){//Test function
    float a[10];
    int l,h;
    cout<<"Vnesi 10 float broja"<<endl;
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    cout<<endl<<"Vnesi od kaj do kaj sakas da gi soberis broevite"<<endl;
    cin>>l>>h;
    cout<<endl<<"Sumata na broevite e "<<Soberi(a,l,h);
return 0;
}
