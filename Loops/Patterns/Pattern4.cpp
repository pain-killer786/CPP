//Write a program to print inverted half pyramid after 180 degree rotation

#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    cout<<"Enter the number of steps";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j<=n-i)
            {
                cout<<" ";
            }
            else
            {
                cout<<"*";
            }
        }
        cout<<endl;
    }
}
