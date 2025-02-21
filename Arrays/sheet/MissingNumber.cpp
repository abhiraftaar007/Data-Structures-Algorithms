#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/missing-number/submissions/

// Solution 1 - Brute Force
int missingNumber(vector<int> &a, int N)
{
    // T.C - O(n^2), S.C - O(1)
    // Outer loop that runs from 1 to N:
    for (int i = 1; i <= N; i++)
    {

        // flag variable to check
        // if an element exists
        int flag = 0;

        // Search the element using linear search:
        for (int j = 0; j < N - 1; j++)
        {
            if (a[j] == i)
            {

                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing
        // i.e flag == 0:

        if (flag == 0)
            return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}

// Solution 2 - Using Hashing
int missingNumber2(vector<int> &a, int N)
{
    // T.C - O(2*n), S.C - O(n)
    int hash[N + 1] = {0}; // hash array

    // storing the frequencies:
    for (int i = 0; i < N - 1; i++) // O(n)
        hash[a[i]]++;

    // checking the freqencies for numbers 1 to N:
    for (int i = 1; i <= N; i++) // O(n)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}

// Solution 3 - Summation Approach
int missingNumber3(vector<int> &a, int N)
{
    // T.C - O(n), S.C - O(1)
    // Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    // Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) // O(n)
    {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
}

// Solution 4 - XOR approach
int missingNumber4(vector<int> &a, int N)
{
    // T.C - O(n), S.C - O(1)
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++) // O(n)
    {
        xor2 = xor2 ^ a[i];    // XOR of array elements
        xor1 = xor1 ^ (i + 1); // XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; // XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 5;
    vector<int> a = {1, 2, 4, 5};

    // int ans = missingNumber(a, N);
    // int ans = missingNumber2(a, N);
    // int ans = missingNumber3(a, N);
    int ans = missingNumber4(a, N);

    cout << "The missing number is: " << ans << endl;

    return 0;
}