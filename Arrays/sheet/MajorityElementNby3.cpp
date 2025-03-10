#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/majority-element-ii/description/

// Brute Force
vector<int> majorityElement(vector<int> v)
{
    // T.C - O(n^2), S.C - O(1)
    int n = v.size(); // size of the array
    vector<int> ls;   // list of answers

    for (int i = 0; i < n; i++)
    {
        // selected element is v[i]:
        //  Checking if v[i] is not already
        //  a part of the answer:
        if (ls.size() == 0 || ls[0] != v[i])
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                // counting the frequency of v[i]
                if (v[j] == v[i])
                {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(v[i]);
        }

        if (ls.size() == 2)
            break;
    }

    return ls;
}

// Better Approach - using Hashing
vector<int> majorityElement2(vector<int> v)
{
    // T.C - O(nlogn), S.C - O(n)
    int n = v.size(); // size of the array
    vector<int> ls;   // list of answers

    // declaring a map:
    map<int, int> mpp;

    // least occurrence of the majority element:
    int mini = int(n / 3) + 1;

    // storing the elements with its occurnce:
    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;

        // checking if v[i] is
        //  the majority element:
        if (mpp[v[i]] == mini)
        {
            ls.push_back(v[i]);
        }
        if (ls.size() == 2)
            break;
    }

    return ls;
}

// Optimal - Moore's voting Algorithm
vector<int> majorityElement3(vector<int> v)
{
    // T.C - O(n)+O(n), S.C - O(1)
    int n = v.size(); // size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN;      // element 1
    int el2 = INT_MIN;      // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && el2 != v[i])
        {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i])
        {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1)
            cnt1++;
        else if (v[i] == el2)
            cnt2++;
        else
        {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == el1)
            cnt1++;
        if (v[i] == el2)
            cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini)
        ls.push_back(el1);
    if (cnt2 >= mini)
        ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement3(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";

    return 0;
}