#include<iostream>
using namespace std;
int main()
{
    int i,j,count;
    cout<<"Enter the number of steps";
    cin>>count;
    for (int i = 1; i < count; i++)
    {
        for(j=1;j<count+1;j++)
        {
            cout<<"*";
        }
        cout<<endl;        
    }
    return 0;
}    
    