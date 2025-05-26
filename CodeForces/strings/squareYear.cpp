#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

// https://codeforces.com/contest/2114/problem/A

// Function to check if a number is a perfect square
bool isPerfectSquare(int n)
{
    if (n < 0)
        return false; // Negative numbers can't be perfect squares

    int root = static_cast<int>(sqrt(n));
    return root * root == n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;

        /*long long num = stoll(s);

        if(isPerfectSquare(num)){
            int a = 0;
            int b = sqrt(num);

            cout << a << " "<< b << "\n";
        }
        else{
            cout << "-1\n";
        }
        */

        // Optimised Way -
        int n = stoi(s);
        if (int(sqrt(n)) * int(sqrt(n)) == n)
        {
            cout << "0 " << int(sqrt(n)) << "\n";
        }
        else
            cout << "-1\n";
    }

    return 0;
}
