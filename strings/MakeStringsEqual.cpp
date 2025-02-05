#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=daily-question&envId=2025-02-05

class Solution
{
public:
    // self-solution
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1 == s2)
            return true;

        string temp_s1 = "", temp_s2 = "";
        int i = 0;
        int n = s1.length();

        while (i < n)
        {
            if (s1[i] != s2[i])
            {
                temp_s1 += s1[i];
                temp_s2 += s2[i];
            }
            if (temp_s1.length() > 2)
                return false;
            i++;
        }

        i = 0;
        int j = temp_s2.length() - 1;

        while (i < j)
        {
            swap(temp_s2[i], temp_s2[j]);
            if (temp_s1 == temp_s2)
                return true;
            i++;
            j--;
        }

        return false;
    }
};

int main()
{
    string a = "bank", b = "kanb";

    Solution obj;

    cout << obj.areAlmostEqual(a,b);

    return 0;
}