// Here we will understand how to initialze an array and take input in it

#include<iostream>
using namespace std;

int main()
{
    int n,i;
    cout<<"Enter the size of Array"<<endl;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter a number";
        cin>>arr[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;    
}