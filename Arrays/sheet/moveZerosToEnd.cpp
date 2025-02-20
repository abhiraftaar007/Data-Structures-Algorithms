#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/move-zeroes/description/

// Brute Force
vector<int> moveZeros(int n, vector<int> a)
{
    // T.C - O(n + nz + n - nz), S.C - O(n)
    // temporary array:
    vector<int> temp; // O(n)
    // copy non-zero elements
    // from original -> temp array:
    for (int i = 0; i < n; i++) // O(n)
    {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }

    // number of non-zero elements.
    int nz = temp.size();

    // copy elements from temp
    // fill first nz fields of
    // original array:
    for (int i = 0; i < nz; i++) // O(nz)
    {
        a[i] = temp[i];
    }

    // fill rest of the cells with 0:
    for (int i = nz; i < n; i++) // O(n-nz)
    {
        a[i] = 0;
    }
    return a;
}

// Optimal Approach
vector<int> moveZeros2(int n, vector<int> a)
{
    // T.C - O(n), S.C - O(1)
    int j = -1;
    // place the pointer j:
    for (int i = 0; i < n; i++) // O(n)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }

    // no non-zero elements:
    if (j == -1)
        return a;

    // Move the pointers i and j
    // and swap accordingly:
    for (int i = j + 1; i < n; i++) // O(n)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;

    vector<int> ans = moveZeros2(n, arr);
    for (auto &it : ans)
    {
        cout << it << " ";
    }

    return 0;
}