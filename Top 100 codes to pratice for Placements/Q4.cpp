#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num1,num2;
    // Prompt the user to enter a number
    cout << "Enter Lower Bound number : ";
    // Read the number from the user
    cin >> num1;
    cout << "Enter Upper Bound number : ";
    // Read the number from the user
    cin>>num2;
    int sum = 0;
    // Calculate the sum of numbers from 1 to n
    for (int i = num1; i <= num2; i++)
        sum += i;
    // Output the sum
    cout << sum;
    return 0;
}