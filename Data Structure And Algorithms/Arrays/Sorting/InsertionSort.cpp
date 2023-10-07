//Insert an element from unsorted array to its correct position in sorted array

#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;

    int arr[n];

    for(i=0;i<n;i++)
    {
        cout<<"Enter a number"<<endl;
        cin>>arr[i];
    }
    
    for(int i=1;i<n;i++)
    {
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}