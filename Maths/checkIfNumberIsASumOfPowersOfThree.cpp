#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/?envType=daily-question&envId=2025-03-04

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        // self-solution
        int i = 0, power = 0;
        while (power <= n)
        {
            power = pow(3, i);
            if (power == n)
                return true;
            if (power > n)
            {
                i--;
                break;
            };
            i++;
        }

        int totalPower = pow(3, i);
        int j = i - 1;

        while (j >= 0)
        {
            int power = pow(3, j);
            if (totalPower + power <= n)
            {
                totalPower += power;
            }
            if (totalPower == n) return true;
            j--;
        }
        return totalPower == n;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 12;
    Solution obj;

    cout << obj.checkPowersOfThree(n);
    
    return 0;
}