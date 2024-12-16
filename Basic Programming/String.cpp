// Strings are 1 dimensional Character Arrays.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    char name[100];

    cout<< "Enter a name"<<endl;
    cin>> name; 
    
    cout<<"Your Name is:- "<<name<<endl;
    cout<<name[3]<<endl;



    string s="Krishnendu Nandy";
    int length= s.size();
    cout<<s<<endl;
    cout<<length<<endl;
    return 0;
}