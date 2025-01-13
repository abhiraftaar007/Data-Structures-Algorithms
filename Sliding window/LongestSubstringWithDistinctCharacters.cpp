#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1

int longestUniqueSubstr(string &s)
{
    // code here
    // using sliding window
    map<char, int> mp;
    int i = 0, j = 0, ans = 0;

    while (j < s.length())
    {
        // Expand the window by adding the current character
        mp[s[j]]++;

        // If the character count exceeds 1, contract the window from the left
        while (mp[s[j]] > 1)
        {
            mp[s[i]]--;
            i++;
        }

        // Update the maximum length of the window
        ans = max(ans, j - i + 1);

        // Move the right pointer to the next character
        j++;
    }

    return ans;
}

int main()
{
    string s = "geeksforgeeks";
    cout << longestUniqueSubstr(s);
    return 0;
}