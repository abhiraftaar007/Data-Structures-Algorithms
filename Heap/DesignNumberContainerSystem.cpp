#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/design-a-number-container-system/description/?envType=daily-question&envId=2025-02-08

class NumberContainers
{
public:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> res;
    unordered_map<int, int> index_val;

    void change(int index, int number)
    {
        if (index_val.count(index))
        {
            int prevNum = index_val[index];
            if (prevNum == number)
                return;
            res[prevNum].push(INT_MAX); // Lazy deletion
        }
        res[number].push(index);
        index_val[index] = number;
    }

    int find(int number)
    {
        while (!res[number].empty() && index_val[res[number].top()] != number)
        {
            res[number].pop();
        }
        return res[number].empty() ? -1 : res[number].top();
    }
};

int main()
{
    NumberContainers* obj = new NumberContainers();
    cout << obj->find(10) << " ";

    obj->change(2,10);
    obj->change(1,10);
    obj->change(3,10);
    obj->change(5,10);

    cout << obj->find(10);

    obj->change(1,20);
    obj->find(10);

    return 0;
}