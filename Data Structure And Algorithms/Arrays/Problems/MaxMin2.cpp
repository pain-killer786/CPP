//Second Approach

#include<bits/stdc++.h>

using namespace std;

int getMax(int arr[],int n)
{
    int max= INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    //returning maximum value
    return max;
}

int getMin(int arr[],int n)
{
    int min= INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    //returning maximum value
    return min;
}

int main()
{
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    int num[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter a number"<<endl;
        cin>>num[i];
    }

    cout<<"Maximum value is"<< getMax(num,size)<<endl;
    cout<<"Minimum value is"<< getMin(num,size)<<endl;
}