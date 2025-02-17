#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/k-largest-elements4206/1

class Solution
{
public:
    // self-solution 1 - using max_heap
    // T.C - O(nlogn + klogn)
    // S.C - O(n+k), n elements stored in max heap, k elements stored in ans array
    vector<int> kLargest(vector<int> &arr, int k)
    {
        vector<int> ans;

        priority_queue<int> max_heap;
        int n = arr.size();

        for (int i = 0; i < n; i++) // O(nlogn)
        {
            max_heap.push(arr[i]); // O(logn)
        }

        while (k > 0) // O(klogn)
        {
            ans.push_back(max_heap.top()); // O(logn)
            max_heap.pop(); // O(logn)
            k--;
        }

        return ans;
    }

    // self-solution 2 - using sorting
    // T.C - O(nlogn+k)
    // S.C - O(k)
    vector<int> kLargest2(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end()); // O(nlogn)

        int j = arr.size() - 1;

        vector<int> ans; // O(k)

        while (k--) // O(k)
        {
            ans.push_back(arr[j--]);
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {12,5,787,1,23};
    int k = 2;

    Solution obj;

    vector<int> ans = obj.kLargest(arr,k);
    // vector<int> ans = obj.kLargest2(arr,k);

    for(auto&i:ans){
        cout << i << " ";
    }

    return 0;
}