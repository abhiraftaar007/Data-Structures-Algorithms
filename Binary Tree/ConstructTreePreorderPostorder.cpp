#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/?envType=daily-question&envId=2025-02-23

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
    TreeNode *solve(int prestart, int poststart, int preend, vector<int> &preorder, vector<int> &postorder)
    {
        if (prestart > preend)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[prestart]);
        if (prestart == preend)
        {
            return root;
        }
        int nextNode = preorder[prestart + 1]; // root of left subtree

        int j = poststart;
        while (postorder[j] != nextNode)
        {
            j++;
        }

        int num = j - poststart + 1;

        root->left = solve(prestart + 1, poststart, prestart + num, preorder, postorder);
        root->right = solve(prestart + num + 1, j + 1, preend, preorder, postorder);

        return root;
    }
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int n = preorder.size();
        return solve(0, 0, n - 1, preorder, postorder);
    }
};

// Function to print inorder traversal
void printInorder(TreeNode *node)
{
    if (node == nullptr)
        return;

    // First recur on left subtree
    printInorder(node->left);

    // Now deal with the node
    cout << node->val << " ";

    // Then recur on right subtree
    printInorder(node->right);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    Solution obj;

    TreeNode* ans = obj.constructFromPrePost(preorder,postorder);
    printInorder(ans);

    return 0;
}