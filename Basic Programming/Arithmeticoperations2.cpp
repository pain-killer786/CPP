// Print all the aritmetic operations using functions

#include<iostream>
#include<cmath>
using namespace std;
int Add(int a, int b) 
{
    int sum;
    sum=a+b;
    return (sum); // return statement is used to give output of function.
}
int Subtract(int a, int b) 
{
    int diff;
    diff=a-b;
    return (diff); // return statement is used to give output of function.
}
int Multiply(int a, int b) 
{
    int pro=1;
    pro=a*b;
    return (pro); // return statement is used to give output of function.
}
int Division(int a, int b) 
{
    int quotient;
    quotient=a/b;
    return quotient;
}
int Modulus(int a, int b) 
{
    int rem;
    rem=a%b;
    return (rem); 
}
int Power(int a, int b) 
{
    int power;
    power=pow(a,b);
    return (power);
}

int main()
{
    int x,y;
    cout<<"Enter two numbers"<<endl;
    cin>>x>>y;
    
    cout<<Add(x, y)<<endl;
    cout<<Subtract(x, y)<<endl;
    cout<<Multiply(x, y)<<endl;
    cout<<Division(x , y ) << endl ;
    cout<<Modulus(x , y )<<endl;
    cout<<Power(x, y)<<endl;
    
    
    return 0;
}
