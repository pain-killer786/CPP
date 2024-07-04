// A number is said to be duck number if it has 0.

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
        if(d==0)
        {
            break;
        }
    }
    if (d==0)
    {
        cout<<"Duck Number"<<endl;
    }
    else
    {
        cout<<"Not a Duck Number"<<endl;
    }
    return 0;
}