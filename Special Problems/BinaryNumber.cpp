// A number is said to be binary number if it contains 1 and 0 only.

#include<iostream>
using namespace std;
int main()
{
    int n,d;
    cout<<"Enter a number"<<endl;
    cin>>n;
    int temp=n;
    while(temp!=0)
    {
        d=temp%10;
        temp/=10;
    }
    if (d==0 || d==1)
    {
        cout<<"Binary Number"<<endl;
    }
    else
    {
        cout<<"Not a Binary Number"<<endl;
    }
    return 0;
}