#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/?envType=study-plan-v2&envId=leetcode-75

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;

        if (root == p || root == q)
            return root;

        // left side se left nikal lo
        TreeNode *leftN = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightN = lowestCommonAncestor(root->right, p, q);

        if (leftN != NULL && rightN != NULL)
            return root;

        if (leftN != NULL)
            return leftN;

        return rightN;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *p = root->left;
    TreeNode *q = root->right;

    Solution obj;
    TreeNode *ans = obj.lowestCommonAncestor(root, p, q);

    cout << ans->val;

    return 0;
}