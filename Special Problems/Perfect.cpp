// A number is said to be perfect if sum of factors = 2* number

#include<iostream>
using namespace std;

int main()
{
    int n,count=0,sum=0;
    cout<<"Enter a number"<<endl;
    cin>>n;
    int temp = n;
    for(int i=1;i<=n;i++)
    {
        if(temp%i==0)
        {
            sum=sum+i;
        }
    }
    if(sum== 2*n)
    {
        cout<<"Perfect Number"<<endl;
    }
    else{
        cout<<"Not a Perfect Number"<<endl;
    }
}
