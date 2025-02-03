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

// Top Down Approach -
int knapSack2(int wt[], int val[], int w, int n)
{
    int t[n + 1][w + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][w];
}

int main()
{
    int wt[4] = {1, 3, 4, 5};
    int val[4] = {1, 4, 5, 7};
    int n = sizeof(wt) / sizeof(wt[0]);
    // int n = wt.size(); for vector
    int w = 7;

    memset(t, -1, sizeof(t));

    cout << knapSack(wt, val, w, n) << '\n';

    cout << knapSack2(wt, val, w, n);

    return 0;
}