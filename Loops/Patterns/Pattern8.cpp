//Write a program to print 

#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    cout<<"Enter the number of steps";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n+1-i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}