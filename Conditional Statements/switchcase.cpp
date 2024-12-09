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
    
    // Input the student's marks
    cout<<"Enter Marks: "<<endl; 
    cin>>marks;

    //We will calculate the grade based on the tens digit of the marks
    switch(marks/10)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4: //Marks below 50
            cout<< "Grade: F"<<endl;
            break;
        case 5: //Marks between 51 and 59
            cout<< "Grade: D"<<endl;
            break;
        case 6: //Marks between 60 and 69
            cout<< "Grade: C"<<endl;
            break;
        case 7: //Marks between 70 and 79
            cout<< "Grade: B"<<endl;
            break;
        case 8: //Marks between 80 and 89
            cout<< "Grade: A"<<endl;
            break;
        case 9: //Marks between 90 and 99
        case 10: //Marks between 100 and 91 (because marks can be at most 100)
            cout<< "Grade: A+"<<endl;
            break;
        default: //For any marks greater than 100 or negative
            cout<< "Invalid Marks"<<endl;
    }
    return 0;
}