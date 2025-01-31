#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1502166201/?envType=study-plan-v2&envId=leetcode-75

// self-solution = brute force
int findKthLargest(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return nums[n - k];
}

// Optimal - using min Heap but max heap is prefered due to minimum pop operations
int findKthLargest2(vector<int> &nums, int k)
{
    // QuickSelect Algorithm is also used to solve this question
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    for (int &num : nums)
    {
        pq.push(num);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    return pq.top(); // T.C - O(n*logk)
}

int main()
{
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    cout << findKthLargest(nums,k);

    return 0;
}