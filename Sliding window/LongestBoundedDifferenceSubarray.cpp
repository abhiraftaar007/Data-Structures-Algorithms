#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1

class Solution
{
public:
    vector<int> longestSubarray(vector<int> &arr, int x)
    {
        // code here
        deque<int> mindq, maxdq;
        int s = 0, e = 0;
        int ansStart = 0, ansEnd = 0;
        vector<int> ans;
        int n = arr.size();
        while (e < n)
        {
            while (!mindq.empty() && arr[mindq.back()] > arr[e])
                mindq.pop_back();
            while (!maxdq.empty() && arr[maxdq.back()] < arr[e])
                maxdq.pop_back();

            mindq.push_back(e);
            maxdq.push_back(e);

            while (arr[maxdq.front()] - arr[mindq.front()] > x)
            {
                if (s == maxdq.front())
                    maxdq.pop_front();
                if (s == mindq.front())
                    mindq.pop_front();
                s++;
            }

            if (e - s > ansEnd - ansStart)
            {
                ansEnd = e;
                ansStart = s;
            }

            e++;
        }

        for (int i = ansStart; i <= ansEnd; i++)
        {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {8,4,2,6,7};
    int x = 4;
    
    Solution obj;
    vector<int> ans = obj.longestSubarray(arr,x);

    for(auto& i: ans){
        cout << i << " ";
    }

    return 0;
}