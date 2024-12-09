// An Armstrong number is a number that is equal to the sum of its digits raised to the power of the number of digits in the number. Example - 153; 153=1^3+5^3+3^3

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,count=0;
    cout<<"Enter a number"<<endl;
    cin>>n;

    int sum=0;
    int originaln = n;
    int temp=n;
    while (temp!=0)
    {
        count++;
        temp/=10;
    }
    while (originaln!=0)
    {
        int d=originaln%10;
        sum=sum+round(pow(d,count));
        originaln=originaln/10;
    }
    
    if(sum==n)
    {
        cout<<"Armstrong"<<endl;
    }
    else
    {
        cout<<"Not Armstrong"<<endl;
    }
    return 0;
}