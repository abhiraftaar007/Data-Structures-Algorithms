#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

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
// using BFS Traversal
int maxLevelSum(TreeNode *root)
{
    int maxSum = INT_MIN;
    int resultLevel = 0;

    queue<TreeNode *> que;
    que.push(root);

    int currLevel = 1;

    while (!que.empty())
    {
        int n = que.size();

        int sum = 0;

        // Traversing all elements of curr Level
        while (n--)
        {
            TreeNode *temp = que.front();
            que.pop();

            sum += temp->val;

            if (temp->left)
            {
                que.push(temp->left);
            }

            if (temp->right)
            {
                que.push(temp->right);
            }
        }

        if (sum > maxSum)
        {
            maxSum = sum;
            resultLevel = currLevel;
        }

        currLevel++;
    }

    return resultLevel;
}

map<int, int> mp;

void DFS(TreeNode *root, int level)
{
    if (!root)
    {
        return;
    }

    mp[level] += root->val;

    DFS(root->left, level + 1);
    DFS(root->right, level + 1);
}

// Solution 2
// using DFS - Inorder Traversal
int maxLevelSum2(TreeNode *root)
{
    mp.clear();

    DFS(root, 1);

    int maxSum = INT_MIN;
    int resultLevel = 0;

    for (auto &it : mp)
    {
        int level = it.first;
        int sum = it.second;

        if (sum > maxSum)
        {
            maxSum = sum;
            resultLevel = level;
        }
    }

    return resultLevel;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(0);
    root->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    root->left->left = new TreeNode(7);

    cout << maxLevelSum2(root);

    return 0;
}