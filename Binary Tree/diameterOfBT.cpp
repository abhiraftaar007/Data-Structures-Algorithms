#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/diameter-of-binary-tree/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int solve(TreeNode *root, int &result)
    {
        if (root == NULL)
            return 0;

        int left = solve(root->left, result);
        int right = solve(root->right, result);

        result = max(result, left + right);

        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int result = INT_MIN;

        solve(root, result);

        return result;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right = new TreeNode(3);

    Solution obj;
    cout << obj.diameterOfBinaryTree(root);

    return 0;
}