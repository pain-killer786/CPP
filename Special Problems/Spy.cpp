// A number is said to be spy number if the sum of digit is equal the product of digit.

#include<iostream>
using namespace std;
int main()
{
    int n,p=1,sum=0;
    cout<<"Enter a number"<<endl;
    cin>>n;
    int temp = n;
    while(temp!=0)
    {
        int d=temp%10;
        p=p*d;
        sum+=d;
        temp/=10;
    }
    if(sum==p)
    {
        cout<<"Spy Number"<<endl;
    }
    else
    {
        cout<<"Not a spy number"<<endl;
    }
    return 0;
}