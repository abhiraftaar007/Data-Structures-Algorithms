#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string temp, ans;
        while (ss >> temp)
        {
            reverse(temp.begin(), temp.end());
            ans += (temp + " ");
        }

        return ans.substr(0, ans.size() - 1);
    }
};

int main()
{
    string s = "Let's take LeetCode contest";
    
    Solution obj;

    cout << obj.reverseWords(s);
    
    return 0;
}