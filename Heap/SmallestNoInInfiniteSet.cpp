#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/smallest-number-in-infinite-set/description/?envType=study-plan-v2&envId=leetcode-75

// Brute Force
class SmallestInfiniteSet
{
public:
    vector<bool> nums;
    int i; // current smallest ko point karega

    SmallestInfiniteSet()
    {
        nums = vector<bool>(1001, true);
        i = 1;
    }

    int popSmallest()
    {
        int result = i;

        nums[i] = false;
        // i++ nhi karenge
        for (int j = i + 1; j < 1001; j++)
        {
            if (nums[j] == true)
            {
                i = j;
                break;
            }
        }

        return result;
    }

    void addBack(int num)
    {
        nums[num] = true;

        if (num < i)
        {
            i = num;
        }
    }
};

// Better Solution
class SmallestInfiniteSet2
{
public:
    int currSmallest;
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;

    SmallestInfiniteSet2()
    {
        currSmallest = 1;
    }

    int popSmallest()
    {
        int result;

        if (!pq.empty())
        {
            result = pq.top();
            pq.pop();
            st.erase(result);
        }
        else
        {
            result = currSmallest;
            currSmallest += 1;
        }

        return result;
    }

    void addBack(int num)
    {
        if (num >= currSmallest || st.find(num) != st.end())
        {
            return;
        }

        st.insert(num);
        pq.push(num);
    }
};

// Best Solution
class SmallestInfiniteSet3
{
public:
    int currSmallest;
    set<int> st;

    SmallestInfiniteSet3()
    {
        currSmallest = 1;
    }

    int popSmallest()
    {
        int result;

        if (!st.empty())
        {
            result = *st.begin();
            st.erase(st.begin());
        }
        else
        {
            result = currSmallest;
            currSmallest += 1;
        }

        return result;
    }

    void addBack(int num)
    {
        if (num >= currSmallest || st.find(num) != st.end())
        {
            return;
        }
        st.insert(num);
    }
};

int main()
{
    
    return 0;
}