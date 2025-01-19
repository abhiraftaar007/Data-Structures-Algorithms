#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/increasing-triplet-subsequence/description/

// Brute Force - TLE
bool increasingTriplet1(vector<int> &nums)
{
    int n = nums.size();

    int i = 0;
    while (i < n - 2)
    {
        int j = i + 1;
        while (j < n - 1)
        {
            if (nums[j] > nums[i])
            {
                int k = j + 1;
                while (k < n)
                {
                    if (nums[k] > nums[j])
                        return true;
                    k++;
                }
            }
            j++;
        }
        i++;
    }

    return false;
}

// ChatGPT - solution 
bool increasingTriplet2(vector<int> &nums)
{
    
    int first = INT_MAX, second = INT_MAX;
    for (int num : nums)
    {
        if (num <= first)
        {
            first = num; // Update first if num is smaller than first
        }
        else if (num <= second)
        {
            second = num; // Update second if num is greater than first but smaller than second
        }
        else
        {
            // If num is greater than both first and second, we found a triplet
            cout << first << " " << second << " " << num;
            cout << endl;
            return true;
        }
    }

    return false;
}

// Youtube solution - same as chatGPT solution
bool increasingTriplet3(vector<int> &nums){
    if(nums.size()<3) return false;

    int left = INT_MAX;
    int mid = INT_MAX;

    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid) {
            cout << left << " " << mid << " " << nums[i];
            cout << endl;
            return true;
        }

        else if(nums[i]>left && nums[i]< mid) mid = nums[i];
        else if(nums[i]<left) left = nums[i];
    }

    return false;
}

int main()
{
    vector<int> arr = {1,5,0,4,1,3};
    cout << increasingTriplet3(arr);
    return 0;
}
