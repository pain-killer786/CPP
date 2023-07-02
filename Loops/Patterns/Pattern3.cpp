//Write a program to print inverted half triangle

#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    cout<<"Enter the number of steps";
    cin>>n;
    for(i=n;i>=1;i--)
    {
        for(j=i;j>=1;j--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}