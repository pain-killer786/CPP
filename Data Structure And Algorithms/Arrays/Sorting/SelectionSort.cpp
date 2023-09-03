// Find the minimum element in unsorted array and swap it with element at the beginning

#include<iostream>
using namespace std;

int main()
{
    int size,i;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;

    int arr[size];

    for(i=0;i<size;i++)
    {
        cout<<"Enter a number"<<endl;
        cin>>arr[i];
    }

    for(i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[i])
            {
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}