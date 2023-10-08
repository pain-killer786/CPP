#include<iostream>
#include<cmath>
using namespace std;
double Squareroot(int x)
{
    double sq;
    sq=sqrt(x);
    return sq;
}
double Cubeoot(int x)
{
    double cb;
    cb=cbrt(x);
    return cb;
}
int main()
{
    int n;
    cout<<"Enter the number to find square root and cube root of it"<<endl;
    cin>>n;
    cout<<"square root is "<<Squareroot(n)<<endl;
    cout<<"cube root is  "<<Cubeoot(n)<<endl;
    return 0;
}
