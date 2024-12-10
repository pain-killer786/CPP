#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(13);

    cout<<"Finding 13-> "<<binary_search(v.begin(), v.end(), 13)<<endl;

    cout<<"Lower Bound-> "<<lower_bound(v.begin(), v.end(), 6) - v.begin()<<endl;
    cout<<"Upper Bound-> "<<upper_bound(v.begin(), v.end(), 13) - v.begin()<<endl;

    int a=4;
    int b=10;

    cout<<"Max-> "<<max(a,b)<<endl;
    cout<<"Min-> "<<min(a,b)<<endl;

    swap(a,b);

    cout<<a<<" "<<b<<endl;

    string abcd ="abcde";
    reverse(abcd.begin(), abcd.end());
    cout<<"String-> "<<abcd<<endl;

    rotate(v.begin(),v.begin()+1, v.end());
    cout<<"After rotate"<<endl;

    for (int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}