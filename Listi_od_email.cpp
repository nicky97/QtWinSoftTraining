#include <iostream>
using namespace std;
#include <list>
#include <algorithm>
#include <string>
#include <iterator>
int main(){
    list<string> e1;//list of emails 1
    list<string> e2;//list of emails 2
    list<string> e3;//list of emails 3
    int n;
    string input;
    cout<<"Vnesi kolku emailovi da ima prvata lista"<<endl;
    cin>>n;//enter how many emails should list 1 have
    cout<<"Vnesi: gi emailovite";
    for(int i=0;i<n;i++){
        cout<<"Vnesi adresa:"; cin>>input;//input the emails
        e1.push_back(input);//add the emails to the list1
    }
    cout<<"Vnesi kolku emailovi da ima vtorata lista"<<endl;
    cin>>n;//input how many emails should list 2 have
    cout<<"Vnesi: gi emailovite";
    for(int i=0;i<n;i++){
        cout<<"Vnesi adresa:"; cin>>input;//input the emails
        e2.push_back(input);//add the emails to list 2
    }
    cout<<"Vnesi kolku emailovi da ima tretata lista"<<endl;
    cin>>n;//input how many emails should list 3 have
    cout<<"Vnesi: gi emailovite";
    for(int i=0;i<n;i++){
        cout<<"Vnesi adresa:"; cin>>input;//input the emails
        e3.push_back(input);//add the emails to the list
    }
    e1.sort();//sort the lists
    e2.sort();
    e3.sort();
    e1.merge(e2);//merge list 1 and 2
    e1.merge(e3);//merge list 12 and 3
    e1.sort();//sort the list
    e1.unique();//remove duplikates
    list<string>::iterator i;//iterator for lists
    for(i=e1.begin();i!=e1.end();i++){
        cout<<*i<<" ";//print the elements
    }
return 0;
}
