#include<bits/stdc++.h> //this includes all the libraries in cpp
using namespace std;
int main()
{
    int a=10; //variable named a stores the value a;
    int *aptr; // Declared a Pointer named aptr
    aptr= &a; // aptr stores the address of a
    int **aqtr=&aptr; //Declared another pointer aqtr which points to the aptr pointer
    cout<<aptr<<endl; //Prints the address of a 
    cout<<*aqtr<<endl; //Prints the value of aptr i.e. the address of a 

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