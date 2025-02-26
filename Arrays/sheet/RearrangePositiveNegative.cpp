#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

vector<int> RearrangebySign(vector<int> A, int n)
{

    // Define 2 vectors, one for storing positive
    // and other for negative elements of the array.
    vector<int> pos;
    vector<int> neg;

    // Segregate the array into positives and negatives.
    for (int i = 0; i < n; i++)
    {

        if (A[i] > 0)
            pos.push_back(A[i]);
        else
            neg.push_back(A[i]);
    }

    // Positives on even indices, negatives on odd.
    for (int i = 0; i < n / 2; i++)
    {

        A[2 * i] = pos[i];
        A[2 * i + 1] = neg[i];
    }

    return A;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> ans = RearrangebySign(nums, nums.size());

    for (auto &i : ans)
    {
        cout << i << " ";
    }

    return 0;
}