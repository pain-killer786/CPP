//Write a program to print Flyod's Triangle

#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    cout<<"Enter the number of steps";
    cin>>n;
    int count=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
}