
#include<iostream>
using namespace std;

int main()
{
    int num; // Variable to store the user input number
    cout<<"Enter a number: "; // Prompt the user to enter a number
    cin>>num; // Read the number from the user

    if(num>0)
    {
        cout<<"Positive"; // Output "Positive" if the number is greater than zero
    }
    else if(num<0)
    {
        cout<<"Negative"; // Output "Negative" if the number is less than zero
    }
    else
    {
        cout<<"Zero"; // Output "Zero" if the number is equal to zero
    }
    return 0; // Return 0 to indicate successful execution
}