#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=leetcode-75

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

// Solution 1
// Using Level Order Traversal i.e BFS
vector<int> rightSideView(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }

    vector<int> result;

    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty())
    {
        int n = que.size();
        TreeNode *node = NULL;

        while (n--)
        {
            node = que.front();
            que.pop();

            if (node->left != NULL)
            {
                que.push(node->left);
            }
            if (node->right != NULL)
            {
                que.push(node->right);
            }
        }

        result.push_back(node->val);
    }

    return result;
}

void preOrder(TreeNode *root, int level, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }

    if (result.size() < level)
    {
        result.push_back(root->val);
    }

    preOrder(root->right, level + 1, result);
    preOrder(root->left, level + 1, result);
}

// Solution 2 -
// Using DFS
// Pre-Order Traversal
vector<int> rightSideView2(TreeNode *root)
{
    vector<int> result;

    preOrder(root, 1, result);

    return result;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);

    vector<int> ans = rightSideView2(root);

    for(auto& i:ans){
        cout << i << " ";
    }

    return 0;
}