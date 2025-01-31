#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/koko-eating-bananas/description/?envType=study-plan-v2&envId=leetcode-75

bool canEatAll(vector<int> &piles, int mid, int h)
{
    int actualHours = 0;

    for (int &x : piles)
    {
        actualHours += x / mid; // hours

        if (x % mid != 0)
        {
            actualHours++;
        }
    }

    return actualHours <= h;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    // Applying binary search
    int n = piles.size();

    int l = 1;
    int r = *max_element(begin(piles), end(piles));

    while (l < r)
    {
        int mid = l + (r - l) / 2; // per hour I can eat mid number of bananas

        if (canEatAll(piles, mid, h))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    return l;
}

int main()
{
    vector<int> piles = {3,6,7,11};
    int h = 8;

    cout << minEatingSpeed(piles,h);
    
    return 0;
}