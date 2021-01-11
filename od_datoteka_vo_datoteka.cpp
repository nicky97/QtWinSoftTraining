#include<iostream>
#include <fstream>
#include <iomanip>
#include<cstring>
#include<vector>
#include<iterator>
using namespace std;

#include <cstdlib>
int main(){
    vector<char*> v;
    char word[100];
    ofstream file("file1.dat", ios::out);
    if(!file){
        cerr<<"Datotekata nemoze da se otvori"<<endl;
        exit(0);
    }
    cout<<"Pisuvaj vo datotekata"<<endl;
    char a[100];
    while(cin>>a){
        file<<a<<" ";
    }
    file.close();
    ifstream filereader("file1.dat", ios::in);
    ofstream filetowrite("writery.dat", ios::out);
    if(!filereader || !filetowrite){
        cerr<<"Fail to read files"<<endl;
        exit(0);
    }
    while(filereader>>word){
        v.push_back(word);
    }
    for(int i=0;i<v.size();i++){
        if(strlen(v[i])<10){
            filetowrite<<word<<" ";
        }
    }
    filereader.close();
    filetowrite.close();
    ifstream fileread("writery.dat", ios::in);
    if(!fileread){
        cerr<<"File cannot be read"<<endl;
        exit(0);
    }
    while(fileread>>word){
        cout<<word<<" ";
    }
return 0;
}
