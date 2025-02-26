#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

// Brute Force
int maxProfit(vector<int> &arr)
{
    // T.C - O(n^2), S.C - O(1)
    int maxPro = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) // O(n)
    {
        for (int j = i + 1; j < n; j++) // O(n)
        {
            if (arr[j] > arr[i])
            {
                maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
    }

    return maxPro;
}

// Optimal Solution -
int maxProfit2(vector<int> &arr)
{
    // T.C - O(n), S.C - O(1)
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) // O(n)
    {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }

    return maxPro;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {7, 1, 5, 3, 6, 4};

    // int maxPro = maxProfit(arr);
    int maxPro = maxProfit2(arr);

    cout << "Max profit is: " << maxPro << endl;

    return 0;
}