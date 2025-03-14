#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Brute Force
    int maximumCandies(vector<int> &candies, long long k)
    {
        // Brute Force
        int n = candies.size();

        int maxC = 0;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            maxC = max(maxC, candies[i]);
            total += candies[i];
        }

        if (total < k)
            return 0;

        // Brute force try from maxC till 1
        for (int c = maxC; c >= 1; c--)
        {
            long long count = 0;

            for (int i = 0; i < candies.size(); i++)
            {
                count += candies[i] / c; // how many children can get c candies from this pile
            }

            if (count >= k)
                return c;
        }

        return 0;
    }

    bool canDistr(vector<int> &candies, int mid, long long k)
    {
        int n = candies.size();

        for (int i = 0; i < n; i++)
        {
            k -= candies[i] / mid;

            if (k <= 0)
            {                // all children got mid candies
                return true; // early return
            }
        }

        return k <= 0; // all children get the mid candies
    }

    
    // optimised  - using binary search
    int maximumCandies2(vector<int> &candies, long long k)
    {
        int n = candies.size();

        int maxC = 0;
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            total += candies[i];
            maxC = max(maxC, candies[i]);
        }

        if (total < k)
            return 0;

        int l = 1, r = maxC, result = 0;
        // T.C - n*log(maxC), S.C - O(1)
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (canDistr(candies, mid, k))
            {
                result = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return result;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> candies = {5,8,6};
    int k = 3;

    Solution obj;
    cout << obj.maximumCandies2(candies, k);
    
    return 0;
}