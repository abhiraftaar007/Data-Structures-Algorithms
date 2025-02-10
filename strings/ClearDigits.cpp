#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/clear-digits/?envType=daily-question&envId=2025-02-10
// https://leetcode.com/problems/backspace-string-compare/description/

class Solution
{
public:
    string clearDigits(string s)
    {
        // self-solution
        int j = s.length() - 1;
        int i = 0;

        while (j >= 0)
        {
            if (s[j] >= '0' && s[j] <= '9')
            {
                s.erase(s.begin() + j);
                i = j - 1;
                while (i >= 0)
                {
                    if (s[i] >= 'a' && s[i] <= 'z')
                    {
                        s.erase(s.begin() + i);
                        break;
                    }
                    i--;
                }
            }
            j--;
        }

        return s;
    }
};

int main()
{
    string s = "ag3";

    Solution obj;

    cout << obj.clearDigits(s);

    return 0;
}