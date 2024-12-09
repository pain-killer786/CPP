// A neon number is a number in which the square of the number is divisible by sum of digits.

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,p,sum=0;
    cout<<"Enter a number"<<endl;
    cin>>n;
    int temp = n;
    while(temp!=0)
    {
        int d=temp%10;
        sum+=d;
        temp/=10;
    }
    p=pow(temp,2);
    if(p%sum==0)
    {
        cout<<"Neon Number"<<endl;
    }
    else
    {
        cout<<"Not a neon number"<<endl;
    }
    return 0;
}