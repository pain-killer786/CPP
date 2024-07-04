// Problen: - Given an array a[] of size n. For every i from 0 to n-1 output max(a[0],a[1],....,a[i])

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

    int mx=-199999999;
    for(i=0;i<n;i++)
    {
        mx=max(mx,arr[i]);
        cout<<mx<<endl;
    }
    return 0;    
}