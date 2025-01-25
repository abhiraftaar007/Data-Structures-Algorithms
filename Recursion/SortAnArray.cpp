#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int temp)
{
    if (v.size() == 0 || v[v.size() - 1] <= temp)
    {
        v.push_back(temp);
        return;
    }

    int val = v[v.size() - 1];
    v.pop_back();

    insert(v, temp);
    v.push_back(val);
    return;
}

void sortt(vector<int> &v)
{
    if (v.size() == 1)
    {
        return;
    }

    int temp = v[v.size() - 1];

    v.pop_back();

    sortt(v);

    insert(v, temp);
}

int main()
{
    vector<int> arr = {2, 3, 7, 6, 4, 5, 9};
    sortt(arr);

    for (auto &i : arr)
    {
        cout << i << " ";
    }

    return 0;
}