#include <bits/stdc++.h>
using namespace std;

// https : // www.geeksforgeeks.org/problems/check-for-bst/1

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    bool isValidBST(Node *root, int minVal, int maxVal)
    {
        if (root == NULL)
            return true;
        if (root->data >= maxVal || root->data <= minVal)
            return false;
        return isValidBST(root->left, minVal, root->data) && isValidBST(root->right, root->data, maxVal);
    }
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node *root)
    {
        // Your code here
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};

int main()
{
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    root->right->right = new Node(5);

    Solution obj;
    cout << obj.isBST(root);

    return 0;
}