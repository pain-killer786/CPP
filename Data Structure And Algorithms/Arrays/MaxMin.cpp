#include<iostream>
using namespace std;

int main()
{
    int n,i;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter a number"<<endl;
        cin>>arr[i];
    }

    int min,max;
    min=max=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
        else if (arr[i]>max)
        {
            max=arr[i];
        }
    }
    cout << "Minimum number: " << min << endl;
    cout << "Maximum number: " << max << endl;
    return 0;
}