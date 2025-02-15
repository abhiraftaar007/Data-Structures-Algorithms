#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/?envType=daily-question&envId=2025-02-15

class Solution
{
public:
    bool check(int i, int currSum, string s, int num, vector<vector<int>> &t)
    {
        if (i == s.length())
        {
            return currSum == num;
        }

        if (currSum > num)
            return false;

        if (t[i][currSum] != -1)
        {
            return t[i][currSum];
        }

        bool possible = false;
        for (int j = i; j < s.length(); j++)
        {
            string sub = s.substr(i, j - i + 1);
            int val = stoi(sub);

            possible = possible || check(j + 1, currSum + val, s, num, t);

            if (possible == true)
                return true;
        }

        return t[i][currSum] = possible;
    }

    // solution 1
    int punishmentNumber(int n)
    {
        int punish = 0;

        for (int num = 1; num <= n; num++)
        { // O(n)
            int sq = num * num;

            string s = to_string(sq);
            vector<vector<int>> t(s.length(), vector<int>(num + 1, -1));

            if (check(0, 0, s, num, t) == true)
            { // O(2^log(n^2)), where digits = log10(N^2)
                punish += sq;
            }
        }

        // T.C - O(n*2^log10(n^2))
        // S.C - [log10(n^2)]*[n] + log10(n^2);

        return punish;
    }

    bool check2(int sq, int currSum, int num)
    {
        if (sq == 0)
            return currSum == num;

        return check2(sq / 10, currSum + sq % 10, num) ||
               check2(sq / 100, currSum + sq % 100, num) ||
               check2(sq / 1000, currSum + sq % 1000, num) ||
               check2(sq / 10000, currSum + sq % 10000, num);
    }

    // Solution 2
    int punishmentNumber2(int n)
    {
        // Solution 2
        int punish = 0;

        // T.C - O(n*2^(log10(n^2)))
        // S.C - O(log10(n^2))

        for (int num = 1; num <= n; num++)
        { // O(N)
            int sq = num * num;

            if (check2(sq, 0, num) == true)
                punish += sq;
        }

        return punish;
    }
};

int main()
{
    int n = 10;
    Solution obj;

    cout << obj.punishmentNumber(n) << '\n';
    cout << obj.punishmentNumber2(n) << '\n';
    
    return 0;
}