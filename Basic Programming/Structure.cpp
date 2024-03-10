#include<iostream>
using namespace std;

typedef struct Employee
{
    int eId;
    char favChar;
    float Salary;
} ep;

union Money
{
    /* data */
    int rice;
    char car;
    float pounds;
};



int main()
{
    enum Meal{breakfast,lunch,dinner};
    cout<<breakfast;
    union Money m1;
    m1.rice=34;
    cout<<m1.rice<<endl;
    struct Employee harry;
    ep shubam;
    harry.eId=1;
    harry.favChar='c';
    harry.Salary=12000000000000000;
    cout<<harry.eId<<endl;
    return 0;
}