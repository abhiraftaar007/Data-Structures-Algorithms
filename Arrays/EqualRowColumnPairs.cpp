#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/equal-row-and-column-pairs/description/?envType=study-plan-v2&envId=leetcode-75

// Brute Force - self-solution - O(N^3)
int equalPairs(vector<vector<int>> &grid)
{
    int count = 0;
    for (int r = 0; r < grid.size(); r++)
    {
        for (int c = 0; c < grid[0].size(); c++)
        {
            bool isEqual = true;
            for (int i = 0; i < grid.size(); i++)
            {
                if (grid[r][i] != grid[i][c])
                {
                    isEqual = false;
                    break;
                }
            }
            if (isEqual)
                count++;
        }
    }

    return count;
}

// Brute Force - Solution 2 
int equalPairs1(vector<vector<int>> &grid)
{
    int n = grid.size();

    int count = 0;

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            int is_equal = true;

            for (int i = 0; i < n; i++)
            {
                if (grid[r][i] != grid[i][c])
                {
                    is_equal = false;
                    break;
                }
            }

            count += is_equal;
        }
    }

    return count;
}

// Optimal Approach
int equalPairs2(vector<vector<int>> &grid)
{
    int n = grid.size();

    int count = 0;

    map<vector<int>, int> mp;

    for (int row = 0; row < n; row++)
    {
        mp[grid[row]]++;
    }

    for (int c = 0; c < n; c++)
    {
        vector<int> temp;

        for (int r = 0; r < n; r++)
        {
            temp.push_back(grid[r][c]);
        }

        count += mp[temp];
    }

    return count;
}

int main()
{  
    vector<vector<int>> arr = {
        {3,2,1},
        {1,7,6},
        {2,7,7}
    };

    cout << equalPairs(arr);

    return 0;
}