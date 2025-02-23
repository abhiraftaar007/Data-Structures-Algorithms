#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int> &arr)
    {
        // code here
        // self -solution
        vector<int> ans;

        stack<int> st;

        int i = arr.size() - 1;

        while (i >= 0)
        {
            while (!st.empty())
            {
                if (st.top() > arr[i])
                {
                    ans.push_back(st.top());
                    break;
                }
                else
                    st.pop();
            }

            if (st.empty())
                ans.push_back(-1);

            st.push(arr[i]);

            i--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {1, 3, 2, 4};
    Solution obj;

    vector<int> ans = obj.nextLargerElement(arr);

    for (auto &i : ans)
    {
        cout << i << " ";
    }

    return 0;
}