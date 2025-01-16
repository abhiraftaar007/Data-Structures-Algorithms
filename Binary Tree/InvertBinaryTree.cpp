#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    invertTree(root->left);
    invertTree(root->right);

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}

// Helper function to print tree in pre-order traversal
void printTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    // Create a symmetric binary tree
    TreeNode *root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(9);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);

    cout << "Original tree (pre-order): ";
    printTree(root1);
    cout << endl;

    // Invert the tree
    root1 = invertTree(root1);

    cout << "Inverted tree (pre-order): ";
    printTree(root1);
    cout << endl;

    return 0;
}
