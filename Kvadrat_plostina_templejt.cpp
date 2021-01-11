#include<iostream>
using namespace std;
template<class T>
class Shape{//virtual interface
    virtual T plostina()const=0;
};//interface ends here
//definicion of template class square starts here
template<class T>
class Square:public Shape<T>{
private:
    T a;//sife of the square
public:
    const T getA()const{return a;}
    void setA(T x){a=(x>0?x:1);}
    virtual T plostina()const{//Area function for square
        return getA()*getA();
    }
    Square & operator =(const Square &right){//assign operator overloaded for square
        setA(right.getA());
        return *this;
    }
    bool operator >(const Square & right){//operator > overloaded for square
        return (plostina()>right.plostina());
    }
    friend ostream & operator <<(ostream &output,const Square & s){//Operator << overloaded for square
        output<<"Stranata e "<<s.getA()<<" Plostinata e "<<s.plostina()<<endl;
        return output;
    }
    friend istream & operator>>(istream &input, Square &s){//operator >> overloaded for square
        cout<<"Vnesi strana ";
        input>>s.a;
        cout<<endl;
        return input;
    }
};

template<class T>
class Rectangle:public Shape<T>{//template class Rectangle
private:
    T a,b;//height and width for the rectangle
public:
    const T getA()const{return a;}
    const T getB()const{return b;}
    void setA(T x){a=(x>0?x:1);}
    void setB(T x){b=(x>0?x:1);}
    virtual T plostina()const{//area function for rectangle
        return getA()*getB();
    }
    Rectangle & operator =(const Rectangle &right){// = operator for rectangle
        setA(right.getA());
        setB(right.getB());
    }
    bool operator >(const Rectangle & right){// > operator overloaded for rectangle
        return(plostina()>right.plostina());
    }
    friend ostream & operator <<(ostream &output,const Rectangle & s){//operator << overloaded for rectangle
        output<<"Stranite se "<<s.getA()<<" "<<s.getB()<<" Plostinata e "<<s.plostina()<<endl;
        return output;
    }
    friend istream & operator>>(istream &input, Rectangle &s){//operator >> overloaded for rectangle
        cout<<"Vnesi sirina ";input>>s.a;
        cout<<endl<<"Vnesi visina ";input>>s.b;
        cout<<endl;
        return input;
    }
};
template<typename T>
void sortirajPole(T*ptr, const int n){//Sorting function implemented with template
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
template<class T>//template print function for array
void pecatiPole(T*ptr, const int &n){
    for(int i=0;i<n;i++){
        cout<<ptr[i];
    }
}//end of print function
int main(){
    Square<float> s[10];//array of squares with float side
    Rectangle<float> r[10];//array of rectangles with float width and height
    cout<<"Vnesi 10 kvadara: "<<endl;
    for(int i=0;i<10;i++){//input the squares
        cin>>s[i];
    }
    cout<<"Vnesi 10 pravoagolnika: "<<endl;
    for(int i=0;i<10;i++){//input the rectangles
        cin>>r[i];
    }
    cout<<"Vneseni se: Kvadrati"<<endl;
    for(int i=0;i<10;i++){//print the squares
        cout<<s[i]<<" ";
    }
    cout<<endl<<"Pravoagolnici"<<endl;
    for(int i=0;i<10;i++){//print the rectangles
        cout<<r[i]<<" ";
    }
    sortirajPole(s,10);//sort the array of squares
    sortirajPole(r,10);//sort the array of rectangles
    cout<<endl<<"Po sortiranje polinjata se "<<endl;
    cout<<"Vneseni se: Kvadari"<<endl;
    for(int i=0;i<10;i++){//print the array of squares after sorting
        cout<<s[i]<<" ";
    }
    cout<<endl<<"Pravoagolnici"<<endl;
    for(int i=0;i<10;i++){//print the array of rectangles after sorting
        cout<<r[i]<<" ";
    }
return 0;
}
