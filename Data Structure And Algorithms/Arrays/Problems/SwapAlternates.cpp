/*Take array as an input and reverse the alternate elements.
Example:- Input:-{1,5,6,3,2,4,9,8}
          Output:-{5,1,3,6,4,2,8,9}*/

#include<bits/stdc++.h>
using namespace std;

void ReverseAlternatives(int arr[], int n)
{
    for(int i=0;i<n;i+=2)
    {
        if(i+1<n)
        {
            swap(arr[i],arr[i+1]);
        }   
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
    ReverseAlternatives(a,size);
    printArray(a,size);
}