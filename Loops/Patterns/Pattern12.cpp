/*Write a program to print the pattern :- "1 2 3 4
                                            5 6 7 8
                                            9 10 11 12*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of steps"<<endl;
    cin>>n;
    int count=1;
    for(int i=1; i<=n ;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
    return 0;
}
