#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1

class Solution
{
public:
    // Code 1
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // Use a max-heap to store the k closest points
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (const auto &point : points)
        {
            int squareDistance = point[0] * point[0] + point[1] * point[1];

            if (maxHeap.size() < k)
            {
                maxHeap.push({squareDistance, point});
            }
            else if (squareDistance < maxHeap.top().first)
            {
                maxHeap.pop();
                maxHeap.push({squareDistance, point});
            }
        }

        // Extract the k closest points from the heap
        vector<vector<int>> result;
        while (!maxHeap.empty())
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }

    // Code 2
    vector<vector<int>> kClosest2(vector<vector<int>> &points, int k)
    {
        // Use a max-heap to store the k closest points
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (int i = 0; i < points.size(); i++)
        {
            int square = points[i][0] * points[i][0] + points[i][1] * points[i][1];

            if (maxHeap.size() < k)
            {
                maxHeap.push({square, points[i]});
            }
            else if (square < maxHeap.top().first)
            {
                maxHeap.pop();
                maxHeap.push({square, points[i]});
            }
        }

        vector<vector<int>> result;
        while (!maxHeap.empty())
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k = 2;

    vector<vector<int>> points = {
        {1, 3},
        {-2, 2},
        {5, 8},
        {0, 1}};

    Solution obj;

    vector<vector<int>> ans = obj.kClosest(points, k);

    for (const auto &a : ans)
    {
        cout << a[0] << " " << a[1] << endl;
    }

    return 0;
}