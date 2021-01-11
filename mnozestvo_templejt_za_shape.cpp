#include <iostream>
using namespace std;
class Shape{//Interface with print and area function
public:
    virtual void print()const=0;
    virtual float plostina()const=0;
};//end of interface
//definition of class square starts here
class Square:public Shape{
private:
    float a;//side of square
public:
    const float getA()const{return a;}
    void setA(float r){a=(r>0?r:1);}
    Square(){
    }
    Square(float a):a(a){//constructor with parameters
    }
    virtual float plostina()const{//area function for square
        return getA()*getA();
    }
    virtual void print()const{cout<<"Kvadrat strana "<<getA()<<" plostina na kvadarot "<<plostina()<<endl;}//print function for Square
    Square &operator =(const Square &r){//Overload = operator for Square
        setA(r.getA());
        return *this;
    }
    bool operator >(const Square &r){//overload > operator for Square
        return plostina()>r.plostina();
    }
    bool operator ==(const Square & right){//overload operator == for Square
        return plostina()==right.plostina();
    }
};//end of class Square

//definition of class circle starts here
class Circle:public Shape{
private:
    float r;//radius of the circle
public:
    void setR(float a){r=(a>0?a:1);}
    const float getR()const{return r;}
    Circle():Shape(){//constructor for the circle
    }
    Circle(float r):r(r){//constructor with parameters
    }
    virtual float plostina()const{return getR()*getR()*3.14;}//Area function for circle
    virtual void print()const{//print circle function
        cout<<"Krug so radius: "<<getR()<<" i plostina: "<<plostina()<<endl;
    }
    bool operator >(const Circle &right){//overload operator > for circle
        return plostina()>right.plostina();
    }
    Circle & operator =(const Circle &right){//overload operator = for circle
        setR(right.getR());
        return *this;
    }
    bool operator ==(const Circle & right){//overload operator == for Circle
        return getR()==right.getR();
    }
};//end of class circle

//Definition of class Rectangle starts here
class Rectangle:public Shape{
private:
    float a,b;//sides of the rectangle
public:
    void setA(float x){a=(x>0?x:1);}
    void setB(float x){b=(x>0?x:1);}
    const float getA()const{return a;}
    const float getB()const{return b;}
    Rectangle(){//constructor for class rectangle
    }
    Rectangle(float a,float b):a(a),b(b){//Constructor with parameter
    }
    virtual float plostina()const{return getA()*getB();}//area function for rectangle
    virtual void print()const{//print function for rectangle
        cout<<"Pravoagolnik ima strani: "<<getA()<<" i "<<getB()<<" i ima plostina "<<plostina()<<endl;
    }
    Rectangle & operator=(const Rectangle &right){//overload operator = for rectangle
        setA(right.getA());
        setB(right.getB());
        return *this;
    }
    bool operator >(const Rectangle &right){//overload opeartor > for rectangle
    return plostina()>right.plostina();
    }
    bool operator ==(const Rectangle & right){//overload operator == for Rectangle
        return(getA()==right.getA()&& getB()==right.getB());
    }
};//end of class rectangle

//definition of template mnozestvo
template<class T>
class Mnozestvo{
private:
    T*ptr;//pointer to T
    int size;//size of the array
public:
    const int getSize()const{return size;}
    Mnozestvo(){//constructor
        size=0;
    }
    ~Mnozestvo(){//destructor
        delete [] ptr;
    }
    void add(T insert){//insert new element function
        if(size==0){//if no elements add the first one
            ptr=new T[1];
            ptr[size++]=insert;
        }
        for(int i=0;i<size;i++){//check if element already exist
            if(ptr[i]==insert)
                return;
        }
        T * tmp=new T[size+1];//allocate new array with +1 size for the new element
        for(int i=0;i<size;i++){
            tmp[i]=ptr[i];//copy the old elements in the new array
        }
        tmp[size++]=insert;//insert the new element as the last element
        delete[]ptr;
        ptr=tmp;
    }
    void print()const{//print all the elements in Mnozestvo function
        if(size==0){
            cout<<"Nema elementi";
            return;
        }
        for(int i=0;i<size;i++){
            ptr[i].print();
        }
    }
    T max(){//find the max element2
        T max=ptr[0];//set the first element to be largest
        for(int i=1;i<size;i++){
            if(ptr[i]>max){//if ptr[i] is larger make him the new max
                max=ptr[i];
            }
        }
        return max;//return max element
    }
};

int main(){
    int choice;//variable for choice in the meny
    Mnozestvo<Circle> c;//empty set of circles
    Mnozestvo<Rectangle> r;//empty set of rectangles
    Mnozestvo<Square> s;//empty set of squares
    float a,b;
    do{
        cout<<"1-dodaj krug   2-dodaj kvadrat  3-dodaj pravoagolnik "<<endl;
        cout<<"4- prikazi pravoagolnici  5- prikazi kvadrati  6 prikazi krugovi "<<endl;
        cout<<"7- prikazi najgolemi elementi  8-prikazi broj na elementi 9-EXIT "<<endl;
        cin>>choice;
        if(choice==1){
            cout<<"Vnesi radius:";cin>>a;
            c.add(Circle(a));//add element to the set of circles
        }
        else if(choice==2){
            cout<<"Vnesi strana: "; cin>>a;
            s.add(Square(a));//add element to the set of squares
        }
        else if(choice==3){
            cout<<"Vnesi sirina i visina"; cin>>a>>b;
            r.add(Rectangle(a,b));//add element to the set of rectangles
        }
        else if(choice==4){
            r.print();//print the rectangle set
        }
        else if(choice==5){
            s.print();//print the square set
        }
        else if(choice==6){
            c.print();//print the circle set
        }
        else if(choice==7){//print the biggest elements of each set
            cout<<endl<<"Najgolemi elementi na krugovi e ";
            c.max().print();
            cout<<endl<<"Najgolemi elementi na pravoagolnici e ";
            r.max().print();
            cout<<endl<<"Najgolemi elementi na kvadrati e ";
            s.max().print();
        }
        else if(choice==8){//print number of elements for each set
            cout<<endl<<"Brojot na krugovi e:"<<c.getSize();
            cout<<endl<<"Brojot na pravoagolici e:"<<r.getSize();
            cout<<endl<<"Brojot na kvadrati e:"<<s.getSize()<<endl;
        }

    }while(choice!=9);
return 0;
}






