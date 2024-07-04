//Binary search is an efficient searching algorithm used to locate a specific target value within a sorted collection of elements. It follows a divide-and-conquer approach, repeatedly dividing the search space in half until the target value is found or until the search space is empty. Binary search has a time complexity of O(log n), where n represents the number of elements in the collection. This means that the time taken to perform a binary search grows logarithmically with the size of the collection.

#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n,int key)
{
    int start=0;
    int end=n;
    while(start<=end)
    {
        int mid=(start+end)/2;

        if(arr[mid]==key)
        {
            return mid;
        }
        else if (arr[mid]>key)
        {
            start=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return -1;
}




int main()
{
    int size,i;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    int key;
    cout<<"Enter the element to be Searched"<<endl;
    cin>>key;

    int arr[size];
    for(i=0;i<size;i++)
    {
        cout<<"Enter a number"<<endl;
        cin>>arr[i];
    }    

    cout<<"Element Found At"<<BinarySearch(arr,size,key)<<endl;

    return 0;
}