#include<bits/stdc++.h>
using namespace std;

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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
            return NULL;
        return bst(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *bst(const vector<int> &nums, int left, int right)
    {
        if (left > right)
            return NULL;
        // Find the middle element
        int midpoint = left + (right - left) / 2;
        // Create the node
        TreeNode *node = new TreeNode(nums[midpoint]);
        // Recursively build the left and right subtrees
        node->left = bst(nums, left, midpoint - 1);
        node->right = bst(nums, midpoint + 1, right);
        return node;
    }
};

// In-order traversal to print the tree
void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void printPreorder(TreeNode *root)
{
    if (root == NULL)
        return;

    // Deal with the node
    cout <<root->val << " ";

    // Recur on left subtree
    printPreorder(root->left);

    // Recur on right subtree
    printPreorder(root->right);
}

int main()
{
    // Example sorted array
    vector<int> nums = {-10, -3, 0, 5, 9};

    // Create a Solution object and call the function
    Solution solution;
    TreeNode *root = solution.sortedArrayToBST(nums);

    // Print the in-order traversal of the BST
    cout << "In-order traversal of the BST: ";
    inorderTraversal(root); // Should print the original sorted array
    cout << endl;

    return 0;
}