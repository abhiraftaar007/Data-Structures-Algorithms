#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/letter-tile-possibilities/submissions/1546001419/?envType=daily-question&envId=2025-02-17

class Solution
{
public:
    int n;

    void solve(string &tiles, vector<bool> &used, unordered_set<string> &result, string &curr)
    {
        result.insert(curr);

        for (int i = 0; i < n; i++)
        {
            if (used[i])
                continue;

            used[i] = true;
            curr.push_back(tiles[i]);

            solve(tiles, used, result, curr);

            used[i] = false;
            curr.pop_back();
        }
    }

    // Solution 1
    int numTilePossibilities(string tiles)
    {
        // Backtracking
        // T.C - O(n!), n = string length
        // S.C - O(n*n!) + O(n)
        n = tiles.length();

        vector<bool> used(n, false);
        unordered_set<string> result;

        string curr = "";

        solve(tiles, used, result, curr);

        return result.size() - 1; // exclude the empty sequence
    }

    int count;
    void solve2(vector<int> &vec)
    {
        count++;

        for (int i = 0; i < 26; i++)
        {
            if (vec[i] == 0)
                continue;

            vec[i]--;   // DO
            solve2(vec); // EXPLORE
            vec[i]++;   // UNDO
        }
    }

    // Solution 2 - Space optimised

    int numTilePossibilities2(string tiles)
    {
        // approach 2 - not using extra space but recursive space
        count = 0;
        vector<int> vec(26, 0);
        for (char &ch : tiles)
        {
            vec[ch - 'A']++;
        }

        solve2(vec);

        return count - 1; // exclude the empty sequence
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string tiles = "AAB";
    Solution obj;

    cout << obj.numTilePossibilities(tiles) << '\n';
    cout << obj.numTilePossibilities2(tiles) << '\n';

    return 0;
}