#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

class Solution
{
public:
    stack<int> st;
    stack<int> minSt; // This will track the minimum elements

    Solution()
    {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x)
    {
        // code here
        st.push(x);
        if (minSt.empty() || x <= minSt.top())
        {
            minSt.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop()
    {
        // code here
        if (!st.empty())
        {
            if (st.top() == minSt.top())
            {
                minSt.pop();
            }
            st.pop();
        }
    }

    // Returns top element of the Stack
    int peek()
    {
        // code here
        if (!st.empty())
        {
            return st.top();
        }
        return -1; // If stack is empty
    }

    // Finds minimum element of Stack
    int getMin()
    {
        // code here
        if (!minSt.empty())
        {
            return minSt.top();
        }
        return -1; // If stack is empty
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution obj;
    obj.push(10);
    cout << obj.getMin() << '\n';
    obj.push(5);
    cout << obj.getMin() << '\n';
    obj.pop();
    
    return 0;
}