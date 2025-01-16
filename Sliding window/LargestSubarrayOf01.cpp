#include<bits/stdc++.h>
using namespace std;

// Brute Force
int maxLen(vector<int> &arr)
{
    // Your code here
    // brute force
    int one = 0;
    int zero = 0;
    int cnt = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        zero = 0;
        one = 0;
        if (arr[i] == 0)
            zero += 1;
        if (arr[i] == 1)
            one += 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == 0)
                zero += 1;
            if (arr[j] == 1)
                one += 1;
            if (zero == one)
                cnt = max(cnt, one + zero);
        }
    }

    return cnt;
}

// Optimal Solution
int maxLen1(vector<int> &arr)
{
    unordered_map<int, int> hM;
    int n = arr.size();
    int sum = 0;
    int max_len = 0;
    int ending_index = -1;

    for (int i = 0; i < n; i++)
    {
        arr[i] = (arr[i] == 0) ? -1 : 1;
    }

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            max_len = i + 1;
            ending_index = i;
        }

        if (hM.find(sum) != hM.end())
        {
            if (max_len < i - hM[sum])
            {
                max_len = i - hM[sum];
                ending_index = i;
            }
        }

        else
        {
            hM[sum] = i;
        }
    }

    return max_len;
}

int main()
{
    vector<int> arr = {1,0,1,1,1,0,0};
    cout << maxLen(arr);
    return 0;
}