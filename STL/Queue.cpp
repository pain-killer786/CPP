#include<iostream>
#include<queue>

using namespace std;

int main()
{
    queue<string> s;

    s.push("Krish");
    s.push("Nendu");
    s.push("Nandy");
    s.push("Merikh");
    s.push("786");

    cout<<"Size before Pop "<<s.size()<<endl;

    cout<<"Front Element "<<s.front()<<endl;
    s.pop();
    cout<<"Front Element "<<s.front()<<endl;

    cout<<"Size after pop "<<s.size()<<endl;

    return 0;
    
}
