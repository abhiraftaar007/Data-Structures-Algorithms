#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array

// Brute Force
vector<int> printLeadersBruteForce(int arr[], int n)
{
    // T.C - O(n^2), S.C - O(n)
    vector<int> ans; // O(n)

    for (int i = 0; i < n; i++) // O(n)
    {
        bool leader = true;

        // Checking whether arr[i] is greater than all
        // the elements in its right side
        for (int j = i + 1; j < n; j++) // O(n)
            if (arr[j] > arr[i])
            {

                // If any element found is greater than current leader
                // curr element is not the leader.
                leader = false;
                break;
            }

        // Push all the leaders in ans array.
        if (leader)
            ans.push_back(arr[i]);
    }

    return ans;
}

vector<int> printLeaders(int arr[], int n)
{
    // T.C - O(n), S.C - O(n)
    vector<int> ans; // O(n)

    // Last element of an array is always a leader,
    // push into ans array.
    int max = arr[n - 1];
    ans.push_back(arr[n - 1]);

    // Start checking from the end whether a number is greater
    // than max no. from right, hence leader.
    for (int i = n - 2; i >= 0; i--) // O(n)
        if (arr[i] > max)
        {
            ans.push_back(arr[i]);
            max = arr[i];
        }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 6;
    int arr[n] = {10, 22, 12, 3, 0, 6};

    vector<int> ans = printLeadersBruteForce(arr, n);

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}