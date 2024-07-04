#include<iostream>
using namespace std;
void table(int x,int y)
{
    int i;
    for(i=1;i<=y;i++)
    {
        cout<<x<<"*"<<i<<"="<<x*i<<endl;
    }
}
int main()
{
    int m,n;
    cout<<"Enter the number"<<endl;
    cin>>m;
    cout<<"Enter the range upto which the table is to be formed"<<endl;
    cin>>n;
    table(m,n);
    return 0;
}