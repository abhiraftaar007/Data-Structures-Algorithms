#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/?envType=daily-question&envId=2025-02-25
class Solution
{
public:
    // Brute force
    int numOfSubarrays(vector<int> &arr)
    {
        int oddSum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            long long sum = 0;
            for (int j = i; j < arr.size(); j++)
            {
                sum += arr[j];
                if (sum % 2 != 0)
                    oddSum++;
            }
        }

        return oddSum;
    }

    // Optimal 1 -
    int M = 1e9 + 7;
    int numOfSubarrays2(vector<int> &arr)
    {
        // Optimal
        int n = arr.size();

        vector<int> prefix(n, 0);
        prefix[0] = arr[0];

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        int count = 0;
        int odd = 0;
        int even = 1;

        for (int i = 0; i < n; i++)
        {
            if (prefix[i] % 2 == 0)
            {
                // odd + even = odd;
                count = (count + odd) % M;
                even++;
            }
            else
            {
                // even + odd = odd
                count = (count + even) % M;
                odd++;
            }
        }

        return count;
    }

    // Optimal 2 -
    // int M = 1e9 + 7;
    int numOfSubarrays3(vector<int> &arr)
    {
        // Optimal 2
        int n = arr.size();

        int count = 0;
        int odd = 0;
        int even = 1;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum % 2 == 0)
            {
                // odd + even = odd;
                count = (count + odd) % M;
                even++;
            }
            else
            {
                // even + odd = odd
                count = (count + even) % M;
                odd++;
            }
        }

        return count;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {1,3,5};
    Solution obj;
    cout << obj.numOfSubarrays3(arr);

    return 0;
}