#include<iostream>
using namespace std;
#include<cstring>
#include<vector>
#include<algorithm>

int main(){
    vector<char>v1;//vector of chars 1
    vector<char>v2;//vector of chars 2
    char word1[20],word2[20];//char variables
    cout<<"Vnesi zbor 1:"; cin>>word1;//enter number 1
    cout<<"Vnesi zbor 2:"; cin>>word2;//enter number 2
    int i=0;
    int l1=strlen(word1);//length of word1
    int l2=strlen(word2);//length of word2
    while(i<l1){
        v1.push_back(word1[i]);//add new char elements to the vector1
    }
    i=0;
    while(i<l2){
        v2.push_back(word2[i]);//add new char elements to the vector2
    }
    sort(v1.begin(),v1.end());//sort the vectors
    sort(v2.begin(),v2.end());//sort the vectors
    if(std::equal(v1.begin(),v1.end(),v2.begin())){//check if vectors are same
       cout<<"Anagrami se"<<endl;
       }
    else{
        cout<<"Ne se anagrami";
    }

    return 0;
}
