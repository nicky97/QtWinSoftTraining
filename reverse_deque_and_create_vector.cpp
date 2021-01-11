#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
int main(){
    deque<int> d;
    d.push_front(6);
    d.push_front(5);
    d.push_front(4);
    d.push_front(3);
    d.push_front(2);
    d.push_front(1);
    vector<int> v;
    deque<int>::iterator i;
    for(i=d.end();i!=d.begin()-1;i--){
        v.push_back(*i);
    }
    vector<int>::iterator r;
    for(r=v.begin();r!=v.end();r++){
        cout<<" "<<*r<<" ";
    }
return 0;
}
