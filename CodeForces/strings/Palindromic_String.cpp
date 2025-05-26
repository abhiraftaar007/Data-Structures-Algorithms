#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/2114/problem/B

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        int one = 0, zero = 0;
        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            if (c == '0')
                zero++;
            else
                one++;
        }

        int un_paired = (n - 2 * k) / 2;
        if (zero >= un_paired && one >= un_paired && (zero - un_paired) % 2 == 0 &&
            (one - un_paired) % 2 == 0)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}
