#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

class Solution
{
public:
    int evaluate(vector<string> &arr)
    {
        // code here
        stack<int> st;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            string token = arr[i];

            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                // Pop the top two elements
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                // Perform the operation based on the operator
                if (token == "+")
                {
                    st.push(a + b);
                }
                else if (token == "-")
                {
                    st.push(a - b);
                }
                else if (token == "*")
                {
                    st.push(a * b);
                }
                else if (token == "/")
                {
                    st.push(a / b);
                }
            }
            else
            {
                // If the token is a number, push it to the stack
                st.push(stoi(token));
            }
        }

        // The result is the last element remaining in the stack
        return st.top();
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> arr = {"2", "3", "1", "*", "+", "9", "-"};
    Solution obj;

    cout << obj.evaluate(arr);
    
    return 0;
}