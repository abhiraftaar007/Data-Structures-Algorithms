#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    // Apply binary search
    sort(potions.begin(), potions.end());
    vector<int> res;
    for (int spell : spells)
    {
        long potion_needed = (success + spell - 1) / spell;
        auto it = lower_bound(potions.begin(), potions.end(), potion_needed);
        res.push_back(potions.end() - it);
    }
    // m - potions size
    // n - spell size
    // T.C - O(mlogm) + O(nlogm) -> sorting potions + (going on every spell)*(Binary search on potions)
    return res;
}

int main()
{
    vector<int> spells = {3,1,2};
    vector<int> potions = {8,5,8};
    int success = 16;
    vector<int> ans = successfulPairs(spells, potions, success);
    for (auto &i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
