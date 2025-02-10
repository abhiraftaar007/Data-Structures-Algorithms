#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/arranging-coins/description/

class Solution
{
public:
    int arrangeCoins(int n)
    {
        // n=5      n-i
        // index 1=> 5-1=4 n=4
        // index 2=> 4-2=2 n=2
        // index 3=> 2-3=-1 n=-1
        int i;     // index
        int k = n; // passing the n value to k
        for (i = 1; i <= n; i++)
        {
            k = k - i;
            if (k < 0)
            {
                return i - 1;
            }
        }
        return 1;
    }
};

int main()
{
    int n = 5;
    
    Solution obj;
    cout << obj.arrangeCoins(n);

    return 0;
}