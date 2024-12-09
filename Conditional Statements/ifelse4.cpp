#include<iostream>
using namespace std;
int main()
{
    int savings;
    cout<<"Enter the amount saved"<<endl;
    cin>>savings;    

    if(savings>5000)
    {
        if(savings>1000)
        {
            cout<<"Roadtrip with Neha"<<endl;

        }
        else
        {
            cout<<"Shopping with neha"<<endl;
        }
    }
    else
    {
        cout<<"Friends"<<endl;
    }
    return 0;
}