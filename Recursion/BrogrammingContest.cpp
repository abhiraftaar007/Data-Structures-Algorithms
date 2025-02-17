#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/2064/problem/A

// int cnt = 0;

// self-solution
void solve(string &s, string &t, int &cnt)
{
    if (s.length() == 0)
        return;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            t += s.substr(i, s.length() - i);
            s.erase(s.begin() + i, s.begin() + s.length());
            cnt++;
            solve(s, t, cnt);
        }
    }

    for (int i = 0; i < t.length(); i++)
    {
        if (t[i] == '0')
        {
            s += t.substr(i, t.length() - i);
            t.erase(t.begin() + i, t.begin() + t.length());
            cnt++;
            solve(s, t, cnt);
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int a;
        cin >> a;

        string s, t = "";
        cin >> s;

        int cnt = 0;

        solve(s, t, cnt);

        cout << cnt << endl;
    }

    return 0;
}