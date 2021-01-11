#include<iostream>
using namespace std;
#include<queue>
#include<vector>


typedef pair<int,int> proces;//define new specialization for pair named proces
int main(){
    int n;//number of processes
    proces p;//array of
    priority_queue<proces> redica_procesi;//Priority queue of processes

    cout<<"Vnesi kolku procesi:";cin>>n;//input the number of processes
    for(int i=0;i<n;i++){
        cout<<"Vnes prioritet:";
        cin>>p.first;//input priority
        cout<<"Vnesi proces:";
        cin>>p.second;//input number
        redica_procesi.push(p);//add the proces
    }
    while(!redica_procesi.empty()){//while there are processes in queue
        cout<<"Process:"<<redica_procesi.top().second<<" Prioritet:"<<redica_procesi.top().first<<endl;//print the process
        redica_procesi.pop();//pop the process
    }


return 0;;
}//end of main
