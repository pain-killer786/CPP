#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the values of A and B"<<endl;
    int a,b,s,d,p,r;
    cin>>a>>b;
    s=a+b;
    d=a-b;
    p=a*b;
    r=a%b;
    cout<<"The sum is:"<<s<<endl;
    cout<<"The difference is:"<<d<<endl;
    cout<<"The product is:"<<p<<endl;
    cout<<"The remainder is:"<<r<<endl;
    return 0;
}