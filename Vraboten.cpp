#include<iostream>
using namespace std;
#include<cstring>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iterator>
//Definition of class Employee
class Employee{
private:
    char name[20];//Name
    int points;//Points
    static int pointValue;//Value of point
public:
    const static int getPointValue(){return pointValue;}//Getter for point
    Employee(char * i, int points=0):points(points){//Predefined constructor
        strcpy(name,i);
    }
    void setName(const char * i){
        strcpy(name,i);
    }
    void setPoints(int i){
        points=i;
    }
    const char* getName()const{return name;}
    const int getPoints()const{return points;}
    float getSalary()const{//Function that calculate slary of employee
        return pointValue*points;
    }
    bool operator <(const Employee &right){//Overloaded function < for sort
        return points<right.points;
    }
    friend int operator+(int d, const Employee & right){//Overloaded Function + for accumulate
        return d+right.points;
    }
    friend ostream & operator <<(ostream &output, const Employee &e){//Overload << function for printing
        output<<"Name:"<<e.getName()<<" Salary:"<<e.getSalary()<<endl;
    }
};
int Employee::pointValue=20;//Initialize the cost of point

//start of main
int main(){
    vector<Employee> p;//Vector of employees
    int n,points;
    char name[20];

    cout<<"Enter how many employers does the company have:";cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter Employee"<<endl;
        cout<<"Name:";cin>>name;
        cout<<"Points:";cin>>points;
        p.push_back(Employee(name,points));//add employee to the company
    }
    vector<Employee>::iterator f,l;//iterators that points to the begining and end of the vector
    f=p.begin();
    l=p.end();
    sort(f,l);//sort the Employees
    double companySalary=accumulate(f,l,0)*Employee::getPointValue();//get The total salary
    ostream_iterator<Employee> output (cout ,"");//ostream operator for employee
    copy(f,l,output);//print the company employees
    cout<<"The entire company salary is:"<<companySalary;//print the total salary
return 0;
}//end of main
