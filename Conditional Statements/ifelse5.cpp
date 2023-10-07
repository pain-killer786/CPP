/* You need to write a program to accept the age of the user and based on the age print if they are eligible for voting or not. Anyone who is 18 year or older can vote and the others can't vote. If the user is eligible to vote. Print "Vote" else print "Can not vote". */

#include<iostream>
using namespace std;
int main()
{
    int age;
    cout<<"Enter your age"<<endl;
    cin>>age;
    if (age>=18)
    {
        cout<<"Vote"<<endl;
    }
    else
    {
        cout<<"Can not Vote"<<endl;
    }
}
