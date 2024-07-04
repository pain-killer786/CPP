//Write a program to check whether a number is armstrong number or not using function
// An Armstrong number is a number that is equal to the sum of its digits raised to the power of the number of digits in the number. Example - 153; 153=1^3+5^3+3^3

#include<iostream>
#include<cmath>
using namespace std;
bool Armstrong(int num)
{
    int sum=0;
    int count=0;
    int originaln = num;
    int temp=num;
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
    
    if(sum==num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    cout<<Armstrong(n)<<endl;
}