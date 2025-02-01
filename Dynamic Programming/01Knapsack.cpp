#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

int t[1000 + 1][1000 + 1];

int knapSack(int wt[], int val[], int w, int n)
{
    if (n == 0 || w == 0)
        return 0;

    if (t[n][w] != -1)
    {
        return t[n][w];
    }

    if (wt[n - 1] <= w)
    {
        return t[n][w] = max(val[n - 1] + knapSack(wt, val, w - wt[n - 1], n - 1), knapSack(wt, val, w, n - 1));
    }

    else if (wt[n - 1] > w)
    {
        return t[n][w] = knapSack(wt, val, w, n - 1);
    }
}

int main()
{
    int wt[4] = {5, 4, 6, 3};
    int val[4] = {10, 40, 30, 50};
    int n = sizeof(wt) / sizeof(wt[0]);
    // int n = wt.size(); for vector
    int w = 5;

    memset(t, -1, sizeof(t));

    cout << knapSack(wt, val, w, n);

    return 0;
}