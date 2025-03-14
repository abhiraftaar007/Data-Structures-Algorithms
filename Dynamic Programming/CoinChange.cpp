#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/coin-change2448/1

int dp[1001][1001];

int solve(vector<int> &coins, int sum, int i)
{
    if (sum < 0)
        return 0;
    if (sum == 0)
        return 1;
    if (i == coins.size())
        return 0;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    int pick = solve(coins, sum - coins[i], i);
    int nopick = solve(coins, sum, i + 1);

    return dp[i][sum] = pick + nopick;
}

int count(vector<int> &coins, int sum)
{
    // code here.
    memset(dp, -1, sizeof(dp));
    return solve(coins, sum, 0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> coins = {1, 2, 3};
    int sum = 4;

    cout << count(coins, sum);

    return 0;
}
