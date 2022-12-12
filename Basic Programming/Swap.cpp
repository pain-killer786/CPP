#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the values of A and B"<<endl;
    int a,b,t;
    cin>>a>>b;
    t=a;
    a=b;
    b=t;
    cout<<"The swapped numbers are:"<<a<<b<<endl;
    return 0;
}