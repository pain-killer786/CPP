// An Armstrong number is a number that is equal to the sum of its digits raised to the power of the number of digits in the number. Example - 153; 153=1^3+5^3+3^3

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;

    int sum=0;
    int originaln = n;
    while (n>0)
    {
        int d=n%10;
        sum=sum+pow(d,3);
        n=n/10;
    }
    
    if(sum==originaln)
    {
        cout<<"Armstrong"<<endl;
    }
    else
    {
        cout<<"Not Armstrong"<<endl;
    }
    return 0;
}