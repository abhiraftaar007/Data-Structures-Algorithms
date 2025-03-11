#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/?envType=daily-question&envId=2025-03-11

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();

        int result = 0;

        vector<int> mp(3, 0); // 0-a, 1-b, 2-c
        // T.C - O(n), S.C - O(1)
        int i = 0;
        int j = 0;
        while (j < n)
        {
            char ch = s[j];
            mp[ch - 'a']++;

            while (mp[0] > 0 && mp[1] > 0 && mp[2] > 0)
            {
                result += (n - j);
                mp[s[i] - 'a']--;
                i++;
            }

            j++;
        }

        return result;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = "abcabc";
    Solution obj;

    cout << obj.numberOfSubstrings(s);
        
    return 0;
}