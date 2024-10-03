#include<bits/stdc++.h>
using namespace std;

int SumArray(int arr[],int n)
{
    int sum=0;
    for(int j=0;j<n;j++)
    {
        sum+=arr[j];
    }
    return sum;
}

int main()
{
    int size;
    cout<<"Enter the Size of the array"<<endl;
    cin>>size;
    int a[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter a number"<<endl;
        cin>>a[i];
    }
    cout<<"The sum of elements of the array is:"<<" "<<SumArray(a,size)<<endl;
}