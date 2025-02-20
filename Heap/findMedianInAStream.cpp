#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1
class Solution
{
public:
    vector<double> getMedian(vector<int> &arr)
    {
        // code here
        priority_queue<int> leftmaxheap;
        priority_queue<int, vector<int>, greater<int>> rightminheap;
        vector<double> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            leftmaxheap.push(arr[i]);

            int ele = leftmaxheap.top();
            rightminheap.push(ele);
            leftmaxheap.pop();

            if (rightminheap.size() > leftmaxheap.size())
            {
                int ele = rightminheap.top();
                leftmaxheap.push(ele);
                rightminheap.pop();
            }
            double median;
            if (leftmaxheap.size() != rightminheap.size())
                median = leftmaxheap.top();
            else
                median = (double)(leftmaxheap.top() + rightminheap.top()) / 2;
            ans.push_back(median);
        }

        return ans;
    }
};

// https://leetcode.com/problems/find-median-from-data-stream/description/
class MedianFinder
{
public:
    priority_queue<int> left_max_heap;                             // max heap
    priority_queue<int, vector<int>, greater<int>> right_min_heap; // min heap
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (left_max_heap.empty() || num < left_max_heap.top())
        {
            left_max_heap.push(num);
        }
        else
        {
            right_min_heap.push(num);
        }

        // Always maintain left_max_heap size one greater than right_min_heap size
        // ya fir, dono ka size equal ho

        if (abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1)
        {
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }
        else if (left_max_heap.size() < right_min_heap.size())
        {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }

    double findMedian()
    {
        if (left_max_heap.size() == right_min_heap.size())
        {
            // matlab even number of elements hue honge

            return (double)(left_max_heap.top() + right_min_heap.top()) / 2;
        }

        // else humara pass odd number of elements hue honge
        return left_max_heap.top();
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {5, 15, 1, 3, 2, 8};

    Solution obj;

    vector<double> ans = obj.getMedian(arr);

    for (auto &i : ans)
    {
        cout << i << " ";
    }

    return 0;
}