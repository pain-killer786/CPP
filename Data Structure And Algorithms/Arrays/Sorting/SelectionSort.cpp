// Find the minimum element in unsorted array and swap it with element at the beginning

#include <iostream>
using namespace std;

// Function to perform Selection Sort
void SelectionSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIndex =i;
        
        // Find the index of the smallest element in the unsorted position
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
        }

        //Swap the smallest element eith the current element at position 'i'
        swap(arr[minIndex], arr[i]);
    }
}

//Main Function
int main()
{
    int size;

    //Input the size of the array
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    
    int arr[size];

    //Input array elements
    for(int i=0;i<size;i++)
    {
        cout<<"Enter a number"<<endl;
        cin>>arr[i];
    }

    //Sort the array using Selection Sort
    SelectionSort(arr, size);

    //Print the Sorted array
    cout<<"The Sorted array is: ";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;

    return 0;
}