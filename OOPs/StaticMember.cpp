#include <bits/stdc++.h>
using namespace std;

class Employee
{
    int id;
    static int count;

public:
    void setData(void)
    {
        cout << "Enter Employee id: ";
        cin >> id;
        count++;
    }
    void getData(void)
    {
        cout << "The id of this employee is " << id <<" and this is employee number "<<count<< endl;
    }

    static void getCount(void)
    {
        cout<<" The value of count is: "<<count<<endl;
    }
};

//Count is the static data member of class Employee
int Employee :: count; //Default value is 0

int main()
{
    Employee harry, zaynab, sukanya;
    // harry.id=21;
    // harry.count++; // cannot do this as id and count are private

    harry.setData();
    harry.getData();
    Employee::getCount();

    zaynab.setData();
    zaynab.getData();
    Employee::getCount();

    sukanya.setData();
    sukanya.getData();
    Employee::getCount();

    return 0;
}