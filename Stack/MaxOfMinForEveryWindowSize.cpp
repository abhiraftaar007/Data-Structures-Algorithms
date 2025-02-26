#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

class Solution
{
public:
    vector<int> maxOfMins(vector<int> &arr)
    {
        // Your code here
        int n = arr.size();
        vector<int> ans(n, 0); // This will store the result

        // Stack to maintain the indices of arr
        stack<int> s;

        // Previous smaller element index (left boundary)
        vector<int> left(n, -1);

        // Next smaller element index (right boundary)
        vector<int> right(n, n);

        // Find the index of the previous smaller element for each element
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                left[i] = s.top();
            }
            s.push(i);
        }

        // Empty the stack and reuse it for finding the next smaller element
        while (!s.empty())
        {
            s.pop();
        }

        // Find the index of the next smaller element for each element
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] > arr[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                right[i] = s.top();
            }
            s.push(i);
        }

        // Now for each element arr[i], we know its range (left[i], right[i])
        // Update the result array for the subarray length in the range (right[i] - left[i] - 1)
        for (int i = 0; i < n; i++)
        {
            int length = right[i] - left[i] - 1;
            ans[length - 1] = max(ans[length - 1], arr[i]);
        }

        // Fill the result array by taking maximum for each subarray length
        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {10,20,30,50,10,70,30};

    Solution obj;
    vector<int> ans = obj.maxOfMins(arr);

    for(auto& i:ans){
        cout << i << " ";
    }

    return 0;
}