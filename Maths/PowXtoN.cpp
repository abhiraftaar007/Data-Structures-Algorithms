#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/powx-n/submissions/1500642627/

// Solution 1
double myPow(double x, int n)
{
    // Used Binary Exponentiation to find the power of x to power n
    // n - > even -> pow(x*x,n/2)
    // n - > odd - > x * pow(x*x, (n-1)/2)

    double ans = 1.0;
    long long nn = n; // 32-bit integer to long conversion to avoid interger overflow conversion
    if (nn < 0)
        nn = -1 * nn;
    while (nn)
    {
        // check for odd n value
        if (nn % 2)
        {
            ans = ans * x;
            nn = nn - 1;
        }
        // for even value case
        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }

    if (n < 0)
        ans = (double)(1.0) / (double)(ans);
    return ans;
}

double solve(double x, long n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return solve(1 / x, -n);

    if (n % 2 == 0)
        return solve(x * x, n / 2);

    return x * solve(x * x, (n - 1) / 2);
}

// Solution 2
double myPow2(double x, int n)
{
    // Recursive Method
    return solve(x, (long)n);
}

int main()
{
    double b = 3.00000;
    int e = 5;

    cout << myPow(b,e);

    return 0;
}