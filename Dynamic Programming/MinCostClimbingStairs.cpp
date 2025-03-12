#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/min-cost-climbing-stairs/description/

class Solution
{
public:
    // Solution 1 - Bottom up approach
    int minCostClimbingStairs(vector<int> &cost)
    {
        // Copied
        int n = cost.size();
        for (int i = 2; i < n; i++)
        {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[n - 1], cost[n - 2]);
    }

    int t[1001];
    int solve(int idx, vector<int> &cost)
    {
        if (idx >= cost.size())
            return 0;

        if (t[idx] != -1)
            return t[idx];

        int a = cost[idx] + solve(idx + 1, cost);
        int b = cost[idx] + solve(idx + 2, cost);

        return t[idx] = min(a, b);
    }

    // Solution 2 - Recursion + memoization
    int minCostClimbingStairs2(vector<int> &cost)
    {
        int n = cost.size();
        memset(t, -1, sizeof(t));
        return min(solve(0, cost), solve(1, cost));
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> cost = {10,15,20};

    Solution obj;
    cout << obj.minCostClimbingStairs2(cost);

    return 0;
}