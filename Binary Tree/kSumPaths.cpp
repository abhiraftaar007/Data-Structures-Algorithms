#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/k-sum-paths/1

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    void solve(Node *root, int k, int currSum, int &count, unordered_map<int, int> &mp)
    {
        if (!root)
            return;

        currSum += root->data;

        if (currSum == k)
            count++;

        if (mp.find(currSum - k) != mp.end())
            count += mp[currSum - k];

        mp[currSum]++;

        solve(root->left, k, currSum, count, mp);
        solve(root->right, k, currSum, count, mp);

        mp[currSum]--;
    }

    int sumK(Node *root, int k)
    {
        // code here
        unordered_map<int, int> mp;
        int count = 0;

        solve(root, k, 0, count, mp);

        return count;
    }
};

int main()
{
    Node* root = new Node(8);
    root->left = new Node(4);
    root->left->left = new Node(3);
    root->left->left->right = new Node(-2);
    root->left->left->left = new Node(3);
    root->left->right = new Node(2);
    root->left->right->right = new Node(1);

    root->right = new Node(5);
    root->right->right = new Node(2);

    int k  = 7;

    Solution obj;

    cout << obj.sumK(root,k);

    return 0;
}