//The list container in the C++ Standard Template Library (STL) is a doubly-linked list implementation. Unlike vectors and deques, which use contiguous memory, a list stores its elements as individual nodes linked together via pointers. Each node contains the data and pointers to the previous and next nodes in the sequence.

#include<iostream>
#include<list>

using namespace std;

int main()
{
    list<int> l;

    


    l.push_back(1);
    l.push_front(2);

    for (int i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    list<int> n(l);

    for (int i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    l.erase(l.begin());
    cout<<"after erase"<<endl;
    for(int i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Size of list "<<l.size()<<endl;
}