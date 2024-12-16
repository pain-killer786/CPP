#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    int ID;
    int Salary;

public:
    string name;

    void setId()
    {
        cout << "Enter the id of the Employee " << endl;
        cin >> ID;
    }

    void setSalary()
    {
        cout << "Enter the salary of the Employee " << endl;
        cin >> Salary;
    }

    void getData()
    {
        cout << "The salary and Id of " << name << " is " << Salary << " and " << ID << endl;
    }
};

int main()
{
    int SIZE;
    cout<<"Enter the number of employees you want to add: ";
    cin>>SIZE;
    Employee employee[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter Employee name: ";
        cin >> employee[i].name;

        employee[i].setId();
        employee[i].setSalary();
    }
    for (int i = 0; i < SIZE; i++)
    {
        employee[i].getData();
    }

    return 0;
}