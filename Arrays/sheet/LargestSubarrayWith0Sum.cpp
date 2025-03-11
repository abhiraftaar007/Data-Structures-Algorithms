#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?category%5B%5D=Hash&company%5B%5D=Amazon&page=1&query=category%5B%5DHashcompany%5B%5DAmazonpage1company%5B%5DAmazoncategory%5B%5DHash&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-subarray-with-0-sum

// Brute Force solution - 
int solve(vector<int> &a)
{
    // T.C - O(n), S.C - O(n)
    int n = a.size();
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }

    return maxi;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << solve(a) << endl;
    
    return 0;
}