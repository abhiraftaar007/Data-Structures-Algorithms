#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/number-of-coins1824/1

int solve(vector<int> &coins, int sum, int idx, vector<vector<int>> &dp)
{
    if (idx == coins.size())
    {
        return INT_MAX;
    }
    if (sum == 0)
    {
        return 0;
    }
    if (dp[sum][idx] != -1)
    {
        return dp[sum][idx];
    }
    int count = INT_MAX;
    if (coins[idx] <= sum)
    {
        int temp = solve(coins, sum - coins[idx], idx, dp);
        if (temp != INT_MAX)
        {
            count = min(1 + temp, count);
        }
    }
    count = min(solve(coins, sum, idx + 1, dp), count);
    return dp[sum][idx] = count;
}

int minCoins(vector<int> &coins, int sum)
{
    // code here
    vector<vector<int>> dp(sum + 1, vector<int>(coins.size() + 1, -1));
    sort(coins.begin(), coins.end(), greater<int>());
    int ans = solve(coins, sum, 0, dp);
    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> coins = {25,10,5};
    int sum = 30;

    cout << minCoins(coins, sum);
    
    return 0;
}