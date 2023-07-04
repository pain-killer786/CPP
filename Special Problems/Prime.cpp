// A prime number is a natural number greater than 1, which is only divisible by 1 and itself. Example - 2,3,5,7,13

#include<iostream>
using namespace std;

int main()
{
    int n,count=0;
    cout<<"Enter a number"<<endl;
    cin>>n;
    int temp = n;
    for(int i=1;i<=temp;i++)
    {
        if(temp%i==0)
        {
            count++;
        }
    }
    if (count==2)
    {
        cout<<"Prime Number"<<endl;
    }
    else
    {
        cout<<"Not a Prime number"<<endl;
    }
}