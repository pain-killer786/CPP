//Insert an element from unsorted array to its correct position in sorted array

#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int n)
{
    //Start from the second element (index 1) because a single element is always "sorted"
    for (int i=1;i<n;i++)
    {
        int key =arr[i]; // The element we want to place in the correct position
        int j=i-1;

        //Move elements of arr[0..i-1] that are greater than 'key' to one position
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }

        //Place 'key in its correct position
        arr[j+1] = key;
    }
}

int main()
{
    int size;

    cout<<"Enter the size of the array"<<endl;
    cin>>size;

    int arr[size];

    for(int i=0;i<size;i++)
    {
        cout<<"Enter the number"<<endl;
        cin>>arr[i];
    }

    InsertionSort(arr,size);


    //Print the Sorted array
    cout<<"The Sorted array is: ";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;

    return 0;
}