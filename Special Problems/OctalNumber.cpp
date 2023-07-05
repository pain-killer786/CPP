// A number is said to be binary number if it contains digits from 0 to 7 only.

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
    if (d>=0 && d<=7)
    {
        cout<<"Octal Number"<<endl;
    }
    else
    {
        cout<<"Not a Octal Number"<<endl;
    }
    return 0;
}