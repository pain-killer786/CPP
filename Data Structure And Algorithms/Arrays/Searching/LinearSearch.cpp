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
        }
    }
    return 0;
}