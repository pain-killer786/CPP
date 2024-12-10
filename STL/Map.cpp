// In the C++ Standard Template Library (STL), a map is an associatibe container that stores key-value pairs in sorted order based on the keys.Maps are one of the most powerful and commonly used data structures in C++. Maps are like Dictionary in Pyhton. The key is unique, and it is used to access the value. Duplicate Keys are not allowed. The map automatically sorts its elements in the ascendinf order of keys (by default) using a comparison function(e.g., <). A map is implemented using a Self-Balancing Binary Search Tree(e.g., Red-Black Tree). A map allows fast key- bsed lookups using O(log n).

#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<int, string> week;

    // Inserting elements using insert()
    week.insert({1, "Sunday"});
    week.insert({2, "Monday"});
    week.insert({3, "Tueday"});
    week.insert({4, "Wedday"});
    week.insert({5, "Thursday"});
    week.insert({6, "Friday"});
    week.insert({7, "Satday"});
    
    //Inserting elements using [] operator
    
    week[3] = "TUESDAY";

    for (auto i:week)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<week[5]<<endl;
    cout<<week.at(6)<<endl;
}