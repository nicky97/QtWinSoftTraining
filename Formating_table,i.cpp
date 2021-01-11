#include <iostream>
using namespace std;
#include <math.h>
#include<iomanip>
//start of main
int main(){
    int n,m;
    cout<<"Enter n:";cin>>n;//input n
    cout<<"Enter m:";cin>>m;//input m
    cout<<fixed;//fixed formating
    cout<<left<<setw(m)<<"i"<<setw(m)<<"i*i"<<setw(m)<<"sqrt(i)"<<setw(m)<<"cbrt(i)"<<endl;//Headers pf the table
    for(int i=1;i<n;i++){
        cout<<left<<setprecision(2)<<setw(m)<<i<<setw(m)<<i*i<<setw(m)<<sqrt(i)<<setw(m)<<cbrt(i)<<endl<<endl;//formated values of table
    }
return 0;
}
//end of main
