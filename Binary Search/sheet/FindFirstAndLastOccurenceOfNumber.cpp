#include <bits/stdc++.h>
using namespace std;

// Brute Force -
int first(int n, int key, vector<int> &v)
{
    int res = -1;
    for (int i = 0; i <= n; i++)
    {
        if (v[i] == key)
        {
            res = i;
            break;
        }
    }
    return res;
}

int Last(int n, int key, vector<int> &v)
{
    int res = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] == key)
        {
            res = i;
            break;
        }
    }
    return res;
}

// Binary Search - Optimised
int firstOcc(vector<int> &nums, int target)
{

    int s = 0, e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (target > nums[mid]) // right wale mai jao
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

int LastOcc(vector<int> &nums, int target)
{

    int s = 0, e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (target > nums[mid]) // right wale mai jao
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> result;
    int firstIndex = firstOcc(nums, target);
    int lastIndex = LastOcc(nums, target);
    result.push_back(firstIndex);
    result.push_back(lastIndex);
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int key = 8;
    vector<int> v = {5, 7, 7, 8, 8, 10};

    // returning the last occurrence index if the element is present otherwise -1
    /* cout << first(v.size(), key, v) << " ";
    cout << Last(v.size(), key, v) << "\n"; */

    vector<int> ans = searchRange(v, key);

    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}