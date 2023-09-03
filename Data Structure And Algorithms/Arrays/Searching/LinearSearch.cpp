//Linear search, also known as sequential search, is a simple searching algorithm used to find a specific target value within a collection of elements. It sequentially checks each element in the collection until the target value is found or until the entire collection has been traversed.Linear search is a straightforward and basic search algorithm that can be applied to any collection, such as an array or a linked list, regardless of whether the elements are sorted or unsorted. However, it has a time complexity of O(n), where n represents the number of elements in the collection.

#include<iostream>
using namespace std;
int main()
{
    int size,key,i;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    cout<<"Enter the element to be searched"<<endl;
    cin>>key;
    int arr[size];
    for(i=0;i<size;i++)
    {
        cout<<"Enter a number"<<endl;
        cin>>arr[i];
    }
    for(i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            cout<<"Element Found at"<<" "<<i<<endl;
            continue;
        }
    }
    return 0;
}