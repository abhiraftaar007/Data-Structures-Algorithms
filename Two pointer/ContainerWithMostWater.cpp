#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/container-with-most-water/description/

int maxArea(vector<int> &height)
{
    // Greedy approach using two pointer
    int n = height.size();
    int i = 0, j = n - 1;
    int maxWater = 0;

    while (i < j)
    {
        int w = j - i;
        int h = min(height[i], height[j]);
        int area = w * h;
        maxWater = max(maxWater, area);

        if (height[i] > height[j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return maxWater;
}

int main()
{
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(arr);
    return 0;
}