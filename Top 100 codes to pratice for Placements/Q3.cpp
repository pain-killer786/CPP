#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    // Prompt the user to enter a number
    cout << "Enter a number : ";
    // Read the number from the user
    cin >> n;
    int sum = 0;
    // Calculate the sum of numbers from 1 to n
    for (int i = 1; i <= n; i++)
        sum += i;
    // Output the sum
    cout << sum;
    return 0;
}