#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/0

// Solution 1 - self solution
void solve(int one, int zero, int n, string op, vector<string> &v)
{
    if (n == 0)
    {
        v.push_back(op);
        return;
    }

    if (one == zero)
    {
        string op1 = op;
        op1.push_back('1');
        solve(one + 1, zero, n - 1, op1, v);
    }
    else
    {
        string op1 = op;
        string op2 = op;
        op1.push_back('1');
        op2.push_back('0');
        solve(one + 1, zero, n - 1, op1, v);
        solve(one, zero + 1, n - 1, op2, v);
    }
}

// Solution 2
void solve2(int one, int zero, int n, string op, vector<string> &v)
{
    if (n == 0)
    {
        v.push_back(op);
        return;
    }

    // one choice is always available
    string op1 = op;
    op1.push_back('1');
    solve2(one + 1, zero, n - 1, op1, v);

    // zero choice
    // when number of 1 is greater than no of zeroes
    if (one > zero)
    {
        string op2 = op;
        op2.push_back('0');
        solve2(one, zero + 1, n - 1, op2, v);
    }
}

vector<string> NBitBinary(int n)
{
    // Your code goes here
    vector<string> v;
    int one = 0;
    int zero = 0;
    string op = "";
    // solve(one, zero, n, op, v);
    solve2(one, zero, n, op, v);

    return v;
}

int main()
{
    int n = 3;
    vector<string> ans = NBitBinary(n);

    for (auto &i : ans)
    {
        cout << i << " ";
    }

    return 0;
}