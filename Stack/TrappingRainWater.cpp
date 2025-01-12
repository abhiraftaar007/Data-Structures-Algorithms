#include<bits/stdc++.h>
using namespace std;

// Code 1
int maxWater(vector<int> &arr)
{
    // code here
    // Code 2
    int n = arr.size();

    // If the array has less than 3 elements, no water can be trapped.
    if (n < 3)
    {
        return 0;
    }

    vector<int> maxL(n), maxR(n), water(n);

    // Fill maxL array with the maximum height from the left up to each index
    maxL[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxL[i] = max(maxL[i - 1], arr[i]);
    }

    // Fill maxR array with the maximum height from the right up to each index
    maxR[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxR[i] = max(maxR[i + 1], arr[i]);
    }

    // Calculate water trapped at each position
    for (int i = 0; i < n; i++)
    {
        water[i] = min(maxL[i], maxR[i]) - arr[i];
    }

    // Sum up the water trapped at each position
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += water[i];
    }

    return sum;
}

// Code 2
int maxWater2(vector<int> &arr)
{
    // code here
    // Brute Force
    int n = arr.size();
    if (n == 0)
        return 0; // Handle edge case for empty array

    vector<int> left(n), right(n);

    // Initialize the left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }

    // Initialize the right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }

    // Calculate the trapped water
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - arr[i]; // Water trapped at index i
    }

    return ans;
}

int main()
{
    vector<int> arr = {3,0,1,0,4,0,2};
    cout << maxWater2(arr);
    return 0;
}