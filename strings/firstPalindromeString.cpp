#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
    string firstPalindrome(vector<string> &words)
    {
        // self-solution
        string ans = "";
        int n = words.size();
        int i = 0;
        while (i < n)
        {
            if (isPalindrome(words[i]))
            {
                ans = words[i];
                return ans;
            };
            i++;
        }

        return ans;
    }
};

int main()
{
    vector<string> words = {"abc", "car", "ada", "racecar", "cool"};

    Solution obj;

    cout << obj.firstPalindrome(words);
    
    return 0;
}