#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-1-bits/submissions/1503876970/

int hammingWeight(int n)
{
    // self-solution
    int cnt = 0;
    while (n > 0)
    {
        int rem = n % 2;
        if (rem == 1)
            cnt++;
        n /= 2;
    }

    return cnt;
}

// Approach 2
int hammingWeight2(int n)
{
    int count = 0;
    for (int i = 31; i >= 0; i--)
    {
        // find the ith bit
        if (((n >> i) & 1) == 1)
        {
            count++;
        }
    }

    return count;
}

// Approach 3
int hammingWeight3(int n)
{
    // unset the rightmost set bit
    // T.C - O(k), k is the no. of 1 bits
    int count = 0;
    while (n)
    {
        n = (n & (n - 1)); // unsetting the right-most set bit
        count++;
    }

    return count;
}

// Approach 4
int hammingWeight4(int n)
{
    return __builtin_popcount(n);
}

int main()
{
    int n = 11;
    cout << hammingWeight(n);
    return 0;
}