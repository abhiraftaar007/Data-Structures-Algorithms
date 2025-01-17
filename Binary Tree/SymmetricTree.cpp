#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/symmetric-tree/?envType=study-plan-v2&envId=top-interview-150

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetricHelp(TreeNode *left, TreeNode *right)
{
    if (left == NULL || right == NULL)
    {
        return left == right;
    }
    if (left->val != right->val)
        return false;

    return isSymmetricHelp(left->left, right->right) &&
           isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(TreeNode *root)
{
    return root == NULL || isSymmetricHelp(root->left, root->right);
}


int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    cout << isSymmetric(root1);

    return 0;
}