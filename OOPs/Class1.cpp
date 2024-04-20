#include<iostream>
using namespace std;

class Employee
{
private:
    int a,b,c; //Private Variables, Can't be accessed directly outside the class

public:
    int d,e; //public variables, Can be accessed and modified from outside of the class
    void setData(int a1,int b1,int c1); //Declaration
    void getData()
    {
        cout<<"The value of a is"<<a<<endl;
        cout<<"The value of b is"<<b<<endl;
        cout<<"The value of c is"<<c<<endl;
        cout<<"The value of d is"<<d<<endl;
        cout<<"The value of e is"<<e<<endl;
    }
};

void Employee :: setData(int a1,int b1, int c1)
{
    a=a1;
    b=b1;
    c=c1;
}

int main()
{
    Employee harry;
    harry.setData(1,2,4);
    harry.d=34;
    harry.e=89;
    harry.getData();
    
    return 0;
}