#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1

class Solution
{
public:
    int maxLength(string &s)
    {
        // code here
        stack<int> st;
        st.push(-1);
        int maxi = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);

            else
            {
                st.pop();
                if (!st.empty())
                    maxi = max(maxi, i - st.top());
                else
                    st.push(i);
            }
        }

        return maxi;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = ")()())";
    Solution obj;
    cout << obj.maxLength(s);
    
    return 0;
}