// Problen: - Given an array a[] of size n. Output sum of each subarray of the given array

#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the Size of the array"<<endl;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter a number"<<endl;
        cin>>a[i];
    }

    int sum=0;

    for(int i=0;i<n-1;i++)
    {
        int sum=0;
        for(int j=i;j<n-1;j++)
        {
            sum+=a[j];
            cout<<sum<<" ";
        }
    }
    return 0;
}