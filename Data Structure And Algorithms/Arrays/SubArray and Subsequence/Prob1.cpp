/*Given an array a[] of size n. Output sum of each subarray of the given array.*/
#include<iostream>  //header file for input output stream
using namespace std;   //namespace to use cout and cin functions without using std:: before them
int main()
{
    int i,n;
    cout<<"Enter the number of elements of the array."<<endl;
    cin>>n;//inputting no.of elements in the array
    int a[n];
    cout<<"Enter the elements of the array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum=0;
        for (int j = i ;j < n;++j)
        {
            sum+=a[j];
             cout << "Sum is "<<sum<< endl;
        }       
    }
    return 0;
}
