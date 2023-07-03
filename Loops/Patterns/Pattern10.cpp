//Write a program to print Rhombus Pattern

#include<iostream>
using namespace std;

int main()
{
    int i,j,n;
    cout<<"Enter the number of steps";
    cin>>n;
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            cout<<" ";
        }
        for(j=1;j<=n;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}