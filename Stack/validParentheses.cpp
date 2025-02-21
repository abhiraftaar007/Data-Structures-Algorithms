#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/description/

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                if (ch == ')' && st.top() == '(' || ch == '}' && st.top() == '{' || ch == ']' && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
    // T.C - O(N)
    // S.C - O(N)
    return false;
}

// https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1
bool isBalanced(string &s)
{
    // code here
    stack<char> open;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            // Push opening brackets onto the stack
            open.push(s[i]);
        }
        else
        {
            // If the stack is empty or the top of the stack doesn't match the closing bracket, return false
            if (open.empty())
                return false;

            char top = open.top();
            if ((s[i] == ']' && top == '[') ||
                (s[i] == '}' && top == '{') ||
                (s[i] == ')' && top == '('))
            {
                // Pop the matching opening bracket
                open.pop();
            }
            else
            {
                return false;
            }
        }
    }

    // If the stack is empty, the string is balanced
    return open.empty();
}

int main()
{
    string s = "()[]{}";
    
    cout << isValid(s) << '\n';

    cout << isBalanced(s);
    return 0;
}