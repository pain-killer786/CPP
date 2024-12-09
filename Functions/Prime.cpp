//Print all prime numbers between 2 given numbers 
// A prime number is a natural number greater than 1, which is only divisible by 1 and itself. Example - 2,3,5,7,13

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
    }
    return true;
}

int main()
{
    int a,b;
    cout<<"Enter a the lower bound and upper bound"<<endl;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
        if(isPrime(i))
        {
            cout<<i<<endl;
        }
}
}

