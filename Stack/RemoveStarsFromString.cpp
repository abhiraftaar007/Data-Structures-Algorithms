#include<bits/stdc++.h>
using namespace std;

// self-solution using Stack
string removeStars(string s)
{
    stack<char> st;
    int i = 0;

    while (i < s.length())
    {
        st.push(s[i]);
        if (st.top() == '*')
        {
            while (st.top() == '*')
            {
                st.pop();
            }
            st.pop();
        }
        i++;
    }

    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s = "leet**cod*e";
    cout << removeStars(s);
    return 0;
}