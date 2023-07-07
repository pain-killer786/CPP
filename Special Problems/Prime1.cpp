// Write a program to print all the prime numbers between two numbers

#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int num)
{
    
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            return false;
        }
        return true;
    }
}

int main()
{
    int a,b;
    cout<<"Enter Two numbers";
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
        if(isPrime(i)==true)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}