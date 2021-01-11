#include<iostream>
using namespace std;
#include<stdlib.h>
#include<algorithm>
#include<vector>
bool neparni(int x){//predicate for odd lements
    return(x%2==0);
}
bool pomali(int x){//predicate for elements smaller than 2000
    return (x<2000);
}
bool interval20004000(int x){//predicate for elements [2000-4000)
    return (x>=2000&&x<4000);
}
bool interval40006000(int x){//predicate for elements [4000-6000)
    return (x>=4000&&x<6000);
}
bool interval60008000(int x){//predicate for elements [6000-8000)
    return (x>=6000&&x<8000);
}
bool interval800010000(int x){//predicate for elements [8000-10000)
    return (x>=8000&&x<10000);
}
static int average=0;
void sredna(int x){//predicate to sum up all numbers
    average+=x;
}
int main(){
    int size=10000;
    int a[size];//create array
    for(int i=0;i<size;i++){
        a[i]=rand()%10000;//initialize random array
    }
    vector<int>r(a,a+size);//insitialize vector from the array
    int n=count_if(r.begin(),r.end(),neparni);//count even elements
    int n1=count_if(r.begin(),r.end(),pomali);//count elements smaller than 2000
    int n2=count_if(r.begin(),r.end(),interval20004000);//count elements in range of 2000 and 4000
    int n3=count_if(r.begin(),r.end(),interval40006000);//count elements in range of 4000 and 6000
    int n4=count_if(r.begin(),r.end(),interval60008000);//count elements in range of 6000 and 8000
    int n5=count_if(r.begin(),r.end(),interval800010000);//count elements in range of 8000 and 10000
    for_each(r.begin(),r.end(),sredna);//sum the elements
    float result=average/size;//find the average of the vector
    cout<<"Broj na parni elementi e:"<<n<<endl<<"Broj na elementi pomali od 2000:"<<n1;
    cout<<endl<<"Broj na elementi vo rang [2000-4000):"<<n2<<endl;
    cout<<"Broj na elementi vo rang [4000-6000):"<<n3<<endl<<"Broj na elementi vo rang [6000-8000):"<<n4<<endl;
    cout<<"Broj na elementi vo rang [8000-10000):"<<n5<<endl<<"Sredna vrednost na elementite e:"<<result;
return 0;
}

