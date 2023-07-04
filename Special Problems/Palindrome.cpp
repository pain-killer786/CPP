// A number is said to be palindrome if it is equal to the reverse of digit.

#include<iostream>
using namespace std;
int main()
{
    int n,r=0,d;
    cout<<"Enter a number";
    cin>>n;
    int temp=n;
    while (temp!=0)
    {
        d=temp%10;
        temp/=10;
        r=r*10+d;
    }
    if (r==n)
    {
        cout<<"Palindrome Number"<<endl;
    }
    else
    {
        cout<<"Not a Palindrome Number"<<endl;
    }
    return 0;    
}