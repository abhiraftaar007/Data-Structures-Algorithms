#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-consecutive-sequence/description/

bool linearSearch(vector<int> &a, int num)
{
    int n = a.size(); // size of array
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
            return true;
    }
    return false;
}

// Brute Force - 
int longestSuccessiveElements(vector<int> &a)
{
    // T.C - O(n^2), S.C - O(1)
    int n = a.size(); // size of array
    int longest = 1;
    // pick a element and search for its
    // consecutive numbers:
    for (int i = 0; i < n; i++) // O(n)
    {
        int x = a[i];
        int cnt = 1;
        // search for consecutive numbers
        // using linear search:
        while (linearSearch(a, x + 1) == true) // O(n)
        {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

// Better - using sorting
int longestSuccessiveElements2(vector<int> &a)
{
    // T.C - O(nlogn) + O(n), S.C - O(1)
    int n = a.size();
    if (n == 0)
        return 0;

    // sort the array:
    sort(a.begin(), a.end()); // O(nlogn)
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    // find longest sequence:
    for (int i = 0; i < n; i++) // O(n)
    {
        if (a[i] - 1 == lastSmaller)
        {
            // a[i] is the next element of the
            // current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller)
        {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// Optimal - using set data structure
int longestSuccessiveElements3(vector<int> &a)
{   
    // T.C - O(3n), S.C - O(n)
    int n = a.size();
    if (n == 0)
        return 0;

    int longest = 1;
    unordered_set<int> st;
    // put all the array elements into set:
    for (int i = 0; i < n; i++) // O(n)
    {
        st.insert(a[i]);
    }

    // Find the longest sequence:
    for (auto it : st) // O(n)
    {
        // if 'it' is a starting number:
        if (st.find(it - 1) == st.end())
        {
            // find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) //O(n)
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a = {100, 200, 1, 2, 3, 4};

    // int ans = longestSuccessiveElements(a);
    // int ans = longestSuccessiveElements2(a);
    int ans = longestSuccessiveElements3(a);

    cout << "The longest consecutive sequence is " << ans << "\n";


    return 0;
}