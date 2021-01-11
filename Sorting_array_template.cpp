#include<iostream>
using namespace std;

template<typename T>
void Sort(T*ptr, const int n){//Sorting algorithm implemented with template
    int i, j;
    T key;
	for (i = 1; i < n; i++)
	{
		j = i;
 		while (j > 0 && ptr[j - 1] > ptr[j])
 		{
 			key = ptr[j];
 			ptr[j] = ptr[j - 1];
 			ptr[j - 1] = key;
 			j--;
 		}
	}
}//end of sorting algoritam

int main(){
    int a[10];
    float b[10];
    cout<<"Enter 10 int elements"<<endl;
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    cout<<"Unsorted elements arra:"<<endl;
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    Sort(a,10);
    cout<<"Sorted elements are:"<<endl;
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter 10 float elements"<<endl;
    for(int i=0;i<10;i++){
        cin>>b[i];
    }
    cout<<"Unsorted elements arra:"<<endl;
    for(int i=0;i<10;i++){
        cout<<b[i]<<" ";
    }
    Sort(b,10);
    cout<<"Sorted elements are:"<<endl;
    for(int i=0;i<10;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}




