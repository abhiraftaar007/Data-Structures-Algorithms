#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/majority-element/submissions/

// Brute Force
int majorityElement(vector<int> v)
{
    // T.C - O(n), S.C - O(1)
    // size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        // selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            // counting the frequency of v[i]
            if (v[j] == v[i])
            {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}

// Better approach - Using map
int majorityElement2(vector<int> v)
{
    // T.C - O(n) + O(nlogn), S.C - O(n)
    // size of the given array:
    int n = v.size();

    // declaring a map:
    map<int, int> mpp; // O(n)

    // storing the elements with its occurnce:
    for (int i = 0; i < n; i++) // O(n)
    {
        mpp[v[i]]++; // O(logn)
    }

    // searching for the majority element:
    for (auto it : mpp)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }

    return -1;
}

// Optimal approach - Moore's Voting Algorithm
int majorityElement3(vector<int> v)
{
    // T.C - O(n) + O(n), S.C - O(1)
    // size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el;      // Element

    // applying the algorithm:
    for (int i = 0; i < n; i++) // O(n)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i])
            cnt++;
        else
            cnt--;
    }

    // checking if the stored element
    //  is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) // O(n)
    {
        if (v[i] == el)
            cnt1++;
    }

    if (cnt1 > (n / 2))
        return el;
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};

    // int ans = majorityElement(arr);
    // int ans = majorityElement2(arr);
    int ans = majorityElement3(arr);

    cout << "The majority element is: " << ans << endl;

    return 0;
}