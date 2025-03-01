#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/make-the-string-great/

class Solution {
public:
    string makeGood(string s) {
        stack<char> stack;
        
        for (char c : s) {
            if (!stack.empty() && abs(c - stack.top()) == 32) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        
        string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        
        return result;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = "leEeetcode";
    Solution obj;
    cout << obj.makeGood(s);
    
    return 0;
}