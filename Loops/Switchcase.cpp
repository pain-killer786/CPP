#include<iostream>
using namespace std;
int main()
{
    char button;
    cout<<"Enter a character"<<endl;
    cin>>button;
    
    switch (button)
    {
        case 'a':
        cout<<"Hello"<<endl;
        break;
        case 'b':
        cout<<"Namaste"<<endl;
        break;
        case 'c':
        cout<<"Salut"<<endl;
        break;
        default:
        break;
    }
}
