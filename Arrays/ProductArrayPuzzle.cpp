#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1

// My Code - Poor Code quality
vector<int> productExceptSelf(vector<int> &arr)
{
    // code here
    int n = arr.size();
    vector<int> ans;
    vector<int> zero(n, 0);
    long long product = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            product *= arr[i];
        if (arr[i] == 0)
            cnt++;
    }

    if (cnt > 1)
        return zero;

    if (cnt == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                ans.push_back(product);
            }
            else
                ans.push_back(0);
        }
        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        ans.push_back(product / arr[i]);
    }

    return ans;
}

// Good Code Quality - ChatGPT
vector<int> productExceptSelf2(vector<int> &arr)
{
    // code here
    int n = arr.size();
    vector<int> ans(n, 1); // Result vector initialized to 1

    long long product = 1;
    int zeroCount = 0;

    // First pass: Calculate the total product and count the zeros
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            product *= arr[i];
        }
        else
        {
            zeroCount++;
        }
    }

    // If there are more than one zero, all the result values will be 0
    if (zeroCount > 1)
    {
        return vector<int>(n, 0);
    }

    // If there is exactly one zero, the result will have the product in place of that zero
    if (zeroCount == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                ans[i] = product;
            }
            else
            {
                ans[i] = 0;
            }
        }
        return ans;
    }

    // If there are no zeros, we can safely calculate the result by dividing the total product
    for (int i = 0; i < n; i++)
    {
        ans[i] = product / arr[i];
    }

    return ans;
}

int main()
{
    vector<int> arr = {12,0};
    vector<int> ans = productExceptSelf(arr);
    for (auto &i : ans)
    {
        cout << i << " ";
    }
    return 0;
}