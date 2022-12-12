#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the value of A:-"<<endl;
    int a;
    cin>>a;
    if (a>0)
    {
        cout<<"Positive Number"<<endl;
    }
    else if(a==0)
    {
        cout<<"Zero"<<endl;
    }
    else{
        cout<<"Negative number:"<<endl;
    }
    return 0;
}