#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &v, int k, int index, int &ans)
{
    if (v.size() == 1)
    {
        ans = v[0];
        return;
    }

    index = (index + k) % v.size();
    v.erase(v.begin() + index);

    solve(v, k, index, ans);

    return;
}

int main()
{
    int n = 40, k = 7;
    vector<int> v(n);
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = i + 1;
    }

    k = k - 1;
    int index = 0;
    int ans = -1;

    solve(v, k, index, ans);

    cout << ans;

    // for (auto &i : v)
    // {
    //     cout << i << " ";
    // }

    return 0;
}