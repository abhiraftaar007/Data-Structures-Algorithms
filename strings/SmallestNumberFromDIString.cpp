#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-smallest-number-from-di-string/submissions/1547085514/?envType=daily-question&envId=2025-02-18

class Solution
{
public:
    bool matchesPattern(string &num, string &pattern)
    {
        for (int i = 0; i < pattern.length(); i++)
        {
            if ((pattern[i] == 'I' && num[i] > num[i + 1]) ||
                (pattern[i] == 'D' && num[i] < num[i + 1]))
            {
                return false;
            }
        }

        return true;
    }
    // Brute Force - find all permuations and compare with DI string
    string smallestNumber(string pattern)
    {
        int n = pattern.length(); // n = 3
        string num = "";

        for (int i = 1; i <= n + 1; i++)
        {
            num.push_back(i + '0'); // i = 1 -> '1'
        }

        // num = "1234"

        while (!matchesPattern(num, pattern))
        {
            next_permutation(begin(num), end(num));
        }

        return num;
    }

    // Approach 2 - using stack - Optimised
    string smallestNumber2(string pattern)
    {
        int n = pattern.length();

        string num = ""; // (n+1) index 0 to n

        int counter = 1;
        stack<char> st;

        for (int i = 0; i <= n; i++)
        {
            st.push(counter + '0');
            counter++;

            if (i == n || pattern[i] == 'I')
            {
                while (!st.empty())
                {
                    num += st.top();
                    st.pop();
                }
            }
        }

        return num;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string pattern = "IIIDIDDD";
    Solution obj;

    cout << obj.smallestNumber2(pattern);
    
    return 0;
}