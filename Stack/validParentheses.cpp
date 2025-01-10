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

int main()
{
    string s = "()[]{}";
    cout << isValid(s);
    return 0;
}