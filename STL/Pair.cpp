#include<bits/stdc++.h>
using namespace std;

// Pairs

// A pair is a simple data structure that can hold two values of different types.
// It is defined in the <utility> header file and can be used to store related data together.

void explainPair()
{
    pair<int ,int> p = {1, 30}; // A pair of integers

    //Accessing the elements of a pair
    cout << "First element of pair: " << p.first << endl; // 1
    cout << "Second element of pair: " << p.second << endl; // 30

    //Nesting pairs
    pair<int, pair<int ,int> > p1 = {1,{3,4}}; // A pair of an integer and a pair of integers
    cout<< p1.first<<" "<< p1.second.second << " "<<p1.second.first<<endl; // 1 4 3


    pair<int,int> arr[] = {{1,2}, {2,5}, {5,1}};
    cout<< arr[1].second;
}

int main()
{
    explainPair();
    return 0;
}

