#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

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

int helper(TreeNode *root, int ans, int curMax)
{
    if (root == NULL)
    {
        return 0;
    }

    int rootAnswer = 0;
    if (root->val >= curMax)
    {
        rootAnswer = 1;
        curMax = root->val;
    }
    int lans = helper(root->left, ans, curMax);
    int rans = helper(root->right, ans, curMax);

    return lans + rans + rootAnswer;
}

// Code 1
int goodNodes(TreeNode *root)
{
    return helper(root, 0, INT_MIN);
}

void countGoodNodes2(TreeNode *root, int &count, int maxForThisStep)
{
    if (root == NULL)
        return;
    if (root->val >= maxForThisStep)
    {
        count++;
        maxForThisStep = root->val;
    }

    countGoodNodes2(root->left, count, maxForThisStep);
    countGoodNodes2(root->right, count, maxForThisStep);
}

// Code 2
int goodNodes2(TreeNode *root)
{
    int count = 0;
    if (!root)
        return count;

    countGoodNodes2(root, count, root->val);

    return count;
}



int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    cout << goodNodes(root);

    return 0;
}