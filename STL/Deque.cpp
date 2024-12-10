// Deque (or doule-ended queue) is a sequence container that allows insertion and deletion from both ends (front and back) efficiently. Deques use numerous fixed static arrays internally for storing elements , but they are more flexible when it comes to inserting/removing elements from both ends.

#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int> d;

    d.push_back(1);
    d.push_front(2);

    for( int i: d)
    {
        cout<<i<<" ";
    }

    cout<<endl;

    cout<<"Print First Element->"<<d.at(1)<<endl;

    cout<<"Front->"<<d.front()<<endl;
    cout<<"Back->"<<d.back()<<endl;

    cout<<"Empty or not"<<d.empty()<<endl;

    cout<<"Before Erase"<<" "<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);
    cout<<"After Erase"<<" "<<d.size()<<endl;



    d.pop_back();

    for( int i: d)
    {
        cout<<i<<" ";
    }

    return 0;

}