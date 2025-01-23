#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/decode-string/

string decodeString(string s)
{
    stack<int> counts;         // Stack to store counts
    stack<string> results;     // Stack to store results
    string currentString = ""; // Current decoded string
    int currentCount = 0;      // Current count

    for (char c : s)
    {
        if (isdigit(c))
        {
            // If the character is a digit, update the current count
            currentCount = currentCount * 10 + (c - '0');
        }
        else if (c == '[')
        {
            // Push the current count and current string onto their respective stacks
            counts.push(currentCount);
            results.push(currentString);
            // Reset current count and current string
            currentCount = 0;
            currentString = "";
        }
        else if (c == ']')
        {
            // Pop from the stacks and build the string
            string temp = currentString;
            currentString = results.top();
            results.pop();
            int count = counts.top();
            counts.pop();
            for (int i = 0; i < count; i++)
            {
                currentString += temp; // Repeat the string count times
            }
        }
        else
        {
            // If it's a letter, add it to the current string
            currentString += c;
        }
    }

    return currentString; // Return the final decoded string
}

int main()
{
    string s = "3[a]2[bc]";
    cout << decodeString(s);
    
    return 0;
}