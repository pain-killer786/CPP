#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=10;
    int *aptr;
    aptr= &a;
    int **aqtr=&aptr;
    cout<<aptr<<endl;
    cout<<*aqtr<<endl;

    return 0;
}

/*Pointer Arithmetic
int main()
{
    int a=10;
    int *aptr=&a;
    cout<<aptr<<endl;

    aptr++;
    aptr--;

    cout<<aptr<<endl;

    return 0;
}*/