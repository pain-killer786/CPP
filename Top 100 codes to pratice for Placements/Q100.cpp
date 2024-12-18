// Write a program to give a string s, remove all its adjacent duplicate characters recursively.

// Input: s = "abbaca"
// Output: "ca"
// Explanation:
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

// Input: s = "azxxzy"
// Output: "ay"
// Explanation:
// For example, in "azxxzy" we could remove "xx" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "azzy", of which only "zz" is possible, so the final string is "ay".

// Constraints:
// 1 <= s.length <= 10^5
// s contains only lowercase English letters.

// Approach:
// 1. We will use a stack to store the characters of the string.
// 2. We will iterate through the string and check if the top of the stack is equal to the current character.
// 3. If it is equal, we will pop the top of the stack.
// 4. If it is not equal, we will push the current character to the stack.
// 5. Finally, we will return the stack as a string.

#include <bits/stdc++.h> // Include all the libraries
using namespace std; // Use the standard namespace

string removeDuplicates(string s, char ch) // Function to remove duplicates
{
    // Base Condition
    if (s.length() <= 1) // If the length of the string is less than or equal to 1
        return s;

    int i = 0; 
    while (i < s.length())      // Iterate through the string
    {
        if (i + 1 < s.length() && s[i] == s[i + 1]) // If the adjacent characters are same
        {
            int j = i;
            while (j + 1 < s.length() && s[j] == s[j + 1]) // Iterate through the string
            {
                j++; // Increment the value of j
            }
            char lastChar = i > 0 ? s[i - 1] : ch; // Store the last character

            string remStr = removeDuplicates(s.substr(j + 1, s.length()), lastChar); // Recursively call the function

            s = s.substr(0, 1); // Store the first character
            int k = s.length(), l = 0; // Initialize the values of k and l

            while (remStr.length() > 0 && s.length() > 0 && remStr[0] == s[s.length() - 1]) // Iterate through the string
            {
                while (remStr.length() > 0 && remStr[0] != ch && remStr[0] == s[s.length() - 1]) // Iterate through the string
                {                
                    remStr = remStr.substr(1, remStr.length()); // Store the substring
                }
                s = s.substr(0, s.length() - 1); // Store the substring
            }
            s = s + remStr; // Store the string
            i = j; // Update the value of i
        }
        else
        {
            i++;
        }
    }
    return s; // Return the string
}

// Driver code

int main()
{
    string s = "abbaca";
    cout << removeDuplicates(s, ' ') << endl;

    s = "azxxzy";
    cout << removeDuplicates(s, ' ') << endl;

    return 0;
}