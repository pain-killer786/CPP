// Set is a container in STL that stores unique elements. It is an implementation of BST(Binary Search Tree). The major difference between set and un-ordered set is that set is slower than unordered set. When you fetch elements in an unordered set, they come in a random way and not in a sorted way. Time Complexity is O(log n).

#include<iostream>
#include<set>

using namespace std;

int main()
{
    set<int> s;

    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(16);
    s.insert(16);
    s.insert(0);
    s.insert(0);
    s.insert(0);

    for (int i:s)
    {
        cout<<i<<endl;
    }

    s.erase(s.begin());

    cout<<"5 is present or not-> "<<s.count(5)<<endl;

    set<int>::iterator itr =s.find(5);

    for(auto it=itr;it!=s.end();it++)
    {
        cout<< *it<<" ";
    }
    cout<<endl;
}