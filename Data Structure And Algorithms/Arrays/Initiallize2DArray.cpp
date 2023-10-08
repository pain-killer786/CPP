// Here we will understand how to initialze a 2D array and take input in it

#include<iostream>
using namespace std;

int main()
{
    int n,m,i,j;
    cout<<"Enter the number of rows in the array"<<endl;
    cin>>n;
    cout<<"Enter the number of columns in the array "<<endl;
    cin >> m ;
    int arr[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<"Enter a number";
            cin>>arr[i][j];
        }
        
    }
    for(i=0;i<n;i++)
    {
        for ( j = 0; j < m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;    
}