#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1
int findEquilibrium(vector<int> &arr)
{
    // code here
    // Prefix sum approach
    int n = arr.size();
    int i = 0;
    int lSum = 0, tSum = 0, rSum = 0;
    for (int i = 0; i < n; i++)
    {
        tSum += arr[i];
    }
    while (i < n)
    {
        rSum = tSum - lSum - arr[i];
        if (lSum == rSum)
            return i;
        lSum += arr[i];
        i++;
    }

    return -1;
}

int main()
{
    vector<int> arr = {1,2,0,3};
    cout << findEquilibrium(arr);
    return 0;
}