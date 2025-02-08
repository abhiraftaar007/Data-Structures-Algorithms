#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/0

int countSubsetSum(vector<int> &arr, int target)
{
    // code here
    // Get the size of the input array
    int n = arr.size();

    // Create a 2D DP table with dimensions (n+1) x (target+1)
    // dp[i][j] represents the number of ways to achieve a sum 'j'
    // using the first 'i' elements of the array
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Base case: There's exactly one way to achieve a
    // sum of 0 (by selecting no elements)
    dp[0][0] = 1;

    // Fill the DP table
    for (int i = 1; i <= n; i++)
    {

        for (int j = 0; j <= target; j++)
        {

            // First, consider excluding the current element
            dp[i][j] = dp[i - 1][j];

            // Then, consider including the current element
            // (if the remaining sum allows it)
            if (j >= arr[i - 1])
            {
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    // Printing the DP table (matrix t)
    cout << "DP Table (Matrix t):" << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // Return the number of ways to achieve the
    // target sum using all elements in the array
    return dp[n][target];
}

int main()
{
    vector<int> arr = {2,3,5,6,8,10};
    int sum = 10;

    cout << countSubsetSum(arr, sum);

    return 0;
}