#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/daily-temperatures/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temp)
    {
        // self-solution
        stack<pair<int, int>> s;
        vector<int> ans;

        int j = temp.size() - 1;
        while (j >= 0)
        {
            if (s.empty())
            {
                ans.push_back(0);
            }
            else
            {
                pair<int, int> p;
                while (!s.empty())
                {
                    p = s.top();
                    if (p.first > temp[j])
                    {
                        ans.push_back(p.second - j);
                        break;
                    }
                    s.pop();
                }
                if (s.empty())
                    ans.push_back(0);
            }
            s.push({temp[j], j});
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    
    Solution obj;

    vector<int> ans = obj.dailyTemperatures(temperatures);

    for (auto &i : ans)
    {
        cout << i << " ";
    }

    return 0;
}