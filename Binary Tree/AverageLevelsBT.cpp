#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/average-of-levels-in-binary-tree/?envType=study-plan-v2&envId=top-interview-150

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution 1
vector<double> averageOfLevels(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }

    queue<TreeNode *> levelQueue;
    levelQueue.push(root);
    levelQueue.push(NULL); // Marker for end of level

    vector<double> avgList;

    while (!levelQueue.empty())
    {
        double sum = 0;
        int nodes = 0;

        // Process nodes at the current level
        while (levelQueue.front() != NULL)
        {
            TreeNode *node = levelQueue.front();
            levelQueue.pop();

            sum += node->val;
            nodes++;

            if (node->left != NULL)
            {
                levelQueue.push(node->left);
            }
            if (node->right != NULL)
            {
                levelQueue.push(node->right);
            }
        }

        // Remove the NULL marker and push it back if there's another level
        levelQueue.pop();

        if (!levelQueue.empty())
        {
            levelQueue.push(NULL);
        }

        avgList.push_back(sum / nodes);
    }

    return avgList;
}

// Solution 2
vector<double> averageOfLevels2(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<double> ans;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            sum += node->val;
            q.pop();
        }

        ans.push_back(sum / n);
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<double> result = averageOfLevels2(root);

    for (double avg : result)
    {
        cout << avg << " ";
    }

    return 0;
}