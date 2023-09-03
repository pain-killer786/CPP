// Repeatedly swap two adjacent elements if they are in Wrong Order.

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

    int count=1;

    while(count<size-1)
    {
        for(int i=0;i<size-count;i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        count++;
    }

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}