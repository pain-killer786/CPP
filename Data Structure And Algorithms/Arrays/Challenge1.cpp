#include<iostream>
using namespace std;
int main()
{
    int n,i;
    int mx= -199999;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(i=0;i<n;i++)
    {        
        cin>>arr[i];
    }

    for(i=0;i<n;i++)
    {
        mx=max(mx,arr[i]);  
        cout<<mx<<endl;              
    }
}