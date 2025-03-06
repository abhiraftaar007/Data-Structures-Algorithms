#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-missing-and-repeated-values/?envType=daily-question&envId=2025-03-06

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int sum = 0, repeated = 0, missing = 0;
        int n = grid.size();           // Assuming grid is an n x n matrix
        vector<int> arr(n * n + 1, 0); // To track frequencies of numbers

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                int num = grid[i][j];
                arr[num]++; // Increment frequency of the number
                sum += num; // Keep track of the sum of numbers
                if (arr[num] == 2)
                {
                    repeated = num; // If a number appears twice, mark it as repeated
                }
            }
        }

        int totalSum = n * n * (n * n + 1) / 2; // Sum of numbers from 1 to n*n
        missing = totalSum - (sum - repeated);  // Calculate the missing number

        return {repeated, missing}; // Return the repeated and missing numbers
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> arr = {
        {1,3},
        {2,2}
    };

    Solution obj;
    vector<int> ans = obj.findMissingAndRepeatedValues(arr);
    
    for(auto& i:ans){
        cout << i << " ";
    }

    return 0;
}