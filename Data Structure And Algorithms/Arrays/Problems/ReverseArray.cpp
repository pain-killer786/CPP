//Take array as an input and reverse it.

#include<bits/stdc++.h>
using namespace std;

void ReverseArray(int arr[],int n)
{
    int start= 0;
    int end= n-1;

    while(start<=end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<<" ";
    }
    
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
    ReverseArray(a,size);
    printArray(a,size);
}