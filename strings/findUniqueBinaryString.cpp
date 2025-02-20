#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-unique-binary-string/?envType=daily-question&envId=2025-02-20

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        unordered_set<int> st;

        for (string &num : nums)
        {
            st.insert(stoi(num, 0, 2));
        }

        int n = nums.size();

        string result = "";

        for (int number = 0; number <= n; number++)
        {
            if (st.find(number) == st.end())
            {
                result = bitset<16>(number).to_string();

                return result.substr(16 - n, n);
            }
        }

        return "";
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> nums = {"111","011","001"};

    Solution obj;
    cout << obj.findDifferentBinaryString(nums);

    return 0;
}