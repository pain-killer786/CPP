/*Write a Program to check the grade of the students based on marks:-
If marks <50, then grade is F
If marks >=50<60, then grade is D
If marks >=60<70, then grade is C
If marks >=70<80, then grade is B
If marks >=80<90, then grade is A
If marks >=90<=100, then grade is A+
If marks are not in the above range then print "Invalid".
*/

#include<iostream>
using namespace std;
int main()
{
    int marks;
    cout<<"Enter Marks: "; 
    cin>>marks;
    if(marks<0 || marks>100)
    {
        cout<<"Invalid"<<endl;
    }
    else if(marks<50)
    {
        cout<<"F"<<endl;
    }   
    else if (marks>=50 && marks<60)
    {
        cout<<"D"<<endl;
    }   
    else if (marks>=60 && marks<70)
    {
        cout<<"C"<<endl;
    }
    else if (marks>=70 && marks<80)
    {
        cout<<"B"<<endl;
    }
    else if(marks>=80 && marks<90)
    {
        cout<<"A"<<endl;
    }
    else if(marks>=90 && marks<=100)
    {
        cout<<"A+"<<endl;
    }

    return 0;
}

