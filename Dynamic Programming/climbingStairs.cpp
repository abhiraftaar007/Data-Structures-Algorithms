#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/climbing-stairs/submissions/1504411614/?envType=study-plan-v2&envId=top-interview-150

// Approach 1 - TLE
int climbStairs(int n)
{
    // Brute Force - Recursive
    // T.C - O(2^N)
    // S.C - O(N) -> stack space
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    int one_step = climbStairs(n - 1);
    int two_step = climbStairs(n - 2);

    return one_step + two_step;
}

// Approach 2 - Memoization
int t[46];
int solve(int n)
{
    if (n < 0)
        return 0;

    if (t[n] != -1)
    {
        return t[n];
    }

    if (n == 0)
        return 1; // we have got 1 way to cover all stairs

    int one_step = solve(n - 1);
    int two_step = solve(n - 2);

    return t[n] = one_step + two_step;
}

int climbStairs2(int n)
{
    // Memoization - better solution
    // store the repeating states
    // as n<=45, take an array of size 46 and store repeating states
    memset(t, -1, sizeof(t));
    return solve(n);
}

// Approach 3 - Bottom Up
int climbStairs3(int n)
{
    // approach 3 - Bottom up approach
    // array[i] = no of ways to climb i stairs
    // array -> 0 1 2 3 ....
    if (n == 1 || n == 2 || n == 3)
        return n;

    vector<int> array(n + 1);
    array[0] = 0;
    array[1] = 1;
    array[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        array[i] = array[i - 1] + array[i - 2];
    }

    return array[n];
}

// Approach 4 - best and optimal
int climbStairs4(int n)
{
    // approach 4 - optimization of approach 3
    // using 3 variables only
    // i ka nikalne k liye, you just need 1 pehle and 2 pehle - (i-1) and (i-2)
    if (n == 1 || n == 2)
        return n;

    int a = 1;
    int b = 2;
    int c = 3;

    for (int i = 3; i <= n; i++)
    {
        c = b + a;
        int temp_b = b;
        b = c;
        a = temp_b;
    }

    return c;
}

int main()
{
    int n = 3;
    cout << climbStairs4(n);
    return 0;
}