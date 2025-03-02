#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

class Solution
{
public:
    vector<int> maxOfSubarrays(vector<int> &arr, int k)
    {
        // code here
        vector<int> ans;
        deque<int> dq; // Deque to store indices of elements
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            // Remove elements from the front if they are out of the current window
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            // Remove elements from the back that are smaller than the current element
            while (!dq.empty() && arr[dq.back()] <= arr[i])
            {
                dq.pop_back();
            }

            // Add the current element index to the deque
            dq.push_back(i);

            // If the window has reached size k, add the maximum element to the result
            if (i >= k - 1)
            {
                ans.push_back(arr[dq.front()]);
            }
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    
    Solution obj;
    vector<int> ans = obj.maxOfSubarrays(arr, k);

    for (auto &i : ans)
    {
        cout << i << " ";
    }

    return 0;
}