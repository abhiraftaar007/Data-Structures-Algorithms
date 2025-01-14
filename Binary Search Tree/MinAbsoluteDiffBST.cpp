#include <bits/stdc++.h>
using namespace std;

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
    // Solution 1
    int minDiff = INT_MAX;
    TreeNode *prev = nullptr; // Initialize prev as nullptr to avoid undefined behavior

    void inOrder(TreeNode *root)
    {
        if (!root)
            return;

        inOrder(root->left); // Traverse Left Subtree

        if (prev != nullptr) // Check if prev is valid (not nullptr)
        {
            minDiff = min(minDiff, root->val - prev->val); // Calculate the minimum difference
        }

        prev = root; // Update prev to the current node

        inOrder(root->right); // Traverse Right Subtree
    }

    int getMinimumDifference(TreeNode *root)
    {
        inOrder(root);  // Start the in-order traversal
        return minDiff; // Return the minimum difference found
    }

    // Solution 2
    int minDiff2 = INT_MAX;

    void inOrder2(TreeNode *root, TreeNode *&prev)
    {
        if (!root)
            return;

        inOrder2(root->left, prev); // L

        if (prev != NULL)
        {
            minDiff = min(minDiff, root->val - prev->val);
        }
        prev = root;

        inOrder2(root->right, prev);
    }
    int getMinimumDifference2(TreeNode *root)
    {
        // BST Inorder -> sorted order
        // Adjacent elements ka diff hi minimum ayega due to sorted order
        TreeNode *prev = NULL;
        inOrder2(root, prev);
        return minDiff;
    }
};

int main()
{
    // Create a simple BST
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Create an instance of the Solution class and compute the minimum difference
    Solution solution;
    int result = solution.getMinimumDifference2(root);

    // Output the result
    cout << "Minimum absolute difference in BST: " << result << endl;

    // Clean up dynamically allocated memory (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
