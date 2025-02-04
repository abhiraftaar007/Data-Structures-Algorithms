#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-palindrome-ii/description/

class Solution
{
public:
    bool isPalindrome(string s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
    bool validPalindrome(string s)
    {
        // self solution
        int n = s.length();

        int i = 0;
        int j = n - 1;

        bool flag = true;

        while (i <= j)
        {
            if (s[i] != s[j])
            {
                flag = false;
                break;
            };
            i++;
            j--;
        }

        if (flag)
            return true;

        bool ans1 = isPalindrome(s, i + 1, j);
        bool ans2 = isPalindrome(s, i, j - 1);

        if (ans1 || ans2)
            return true;

        return false;
    }
};

int main()
{
    string s = "abca";

    Solution obj;
    cout << obj.validPalindrome(s);

    return 0;
}