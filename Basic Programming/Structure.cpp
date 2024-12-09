#include<iostream>
using namespace std;
/*Structures are used to combine different types of data types, just like an array is used to combine the same type of data types.
 typedef is a keyword that is used to assign a new name to any existing data-type.
*/

typedef struct Employee
{
    int eId;
    char favChar;
    float Salary;
} ep;


/*A union is a type of structure that can be used where the amount of memory used is a key factor. 

    Similarly to the structure, the union can contain different types of data types.
    Each time a new variable is initialized from the union it overwrites the previous in C language but in C++ we also don’t need this keyword and uses that memory location.
    This is most useful when the type of data being passed through functions is unknown, using a union which contains all possible data types can remedy this problem.
    It is declared by using the keyword “union“.*/
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