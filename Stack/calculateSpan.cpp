#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
class Solution
{
public:
    vector<int> calculateSpan(vector<int> &arr)
    {
        // write code here
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            int len = 1;
            while (!st.empty() && arr[i] >= arr[st.top()])
            {
                len = max(len, i - st.top() + ans[st.top()]);
                st.pop();
            }

            ans.push_back(len);

            st.push(i);
        }

        return ans;
    }
};

// https://leetcode.com/problems/online-stock-span/description/
class StockSpanner
{
public:
    stack<pair<int, int>> st; // pair of {price, span}
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1; //  currently span of price is 1 which is itself

        while (!st.empty() && st.top().first <= price)
        {
            span = span + st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    
    Solution obj;
    vector<int> ans = obj.calculateSpan(arr);

    for(auto& i:ans){
        cout << i << " ";
    }

    return 0;
}