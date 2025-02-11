#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/?envType=daily-question&envId=2025-02-11

class Solution
{
public:
    // Brute Force
    string removeOccurrences(string s, string part)
    {
        while (s.length() != 0 && s.find(part) < s.length())
        {
            s.erase(s.find(part), part.length());
        }
        return s;
    }

    bool check(stack<char> &st, string &part, int n)
    {
        stack<char> tempSt = st;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            if (tempSt.top() != part[idx])
                return false;

            tempSt.pop();
        }

        return true;
    }

    // Using stack
    string removeOccurrences2(string s, string part)
    {
        stack<char> st;
        int m = s.length();
        int n = part.length();

        for (int i = 0; i < m; i++) // O(m)
        {
            st.push(s[i]);
            if (st.size() >= n && check(st, part, n) == true) //  O(n)
            {
                for (int j = 0; j < n; j++)
                    st.pop();
            }
        }

        string result = "";
        while (!st.empty()) // O(n)
        {
            result.push_back(st.top());
            st.pop();
        }

        reverse(begin(result), end(result));
        return result;
    }

    // Using String
    string removeOccurrences3(string s, string part)
    {
        // T.C - O(m*n)
        string result = "";
        int n = part.length();

        for (char &ch : s)
        {
            result.push_back(ch);
            if (result.length() >= n && result.substr(result.length() - n) == part)
            {
                result.erase(result.length() - n);
            }
        }

        return result;
    }
    // Try to solve using KMP Algorithm
    
};

int main()
{
    string s = "daabcbaabcbc", part = "abc";

    Solution obj;
    cout << obj.removeOccurrences(s, part) << '\n';
    cout << obj.removeOccurrences2(s, part) << '\n';
    cout << obj.removeOccurrences3(s, part) << '\n';

    return 0;
}