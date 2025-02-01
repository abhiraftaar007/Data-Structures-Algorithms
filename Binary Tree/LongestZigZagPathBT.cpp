#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/?envType=study-plan-v2&envId=leetcode-75

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
    int maxPath = 0;

    void solve(TreeNode *root, int steps, bool goLeft)
    {
        if (root == NULL)
            return;

        maxPath = max(maxPath, steps);

        if (goLeft == true)
        {
            solve(root->left, steps + 1, false);
            solve(root->right, 1, true);
        }
        else
        {
            solve(root->right, steps + 1, true);
            solve(root->left, 1, false);
        }
    }

    int longestZigZag(TreeNode *root)
    {
        // Approach 1
        solve(root, 0, true);
        solve(root, 0, false);

        return maxPath;
    }

    int maxPath2 = 0;

    void solve2(TreeNode *root, int left, int right)
    {
        if (root == NULL)
            return;

        maxPath2 = max({maxPath2, left, right});

        solve2(root->left, right + 1, 0);
        solve2(root->right, 0, left + 1);
    }

    // Approach 2
    int longestZigZag2(TreeNode *root)
    {
        solve2(root, 0, 0);

        return maxPath2;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    root->right->right->left = new TreeNode(1);
    root->right->right->left->right = new TreeNode(1);
    root->right->right->left->right->right = new TreeNode(1);

    Solution obj;

    cout << obj.longestZigZag(root) << '\n';

    cout << obj.longestZigZag2(root);

    return 0;
}