#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/construct-tree-1/1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution
{
public:
    int pos;
    Node *solve(vector<int> &inorder, vector<int> &preorder, int str, int end)
    {
        if (str > end)
        {
            return NULL;
        }

        // Create root node from the current preorder element
        Node *root = new Node(preorder[pos++]);

        // Find the position of the root node in inorder traversal
        int div = 0;
        for (int i = str; i <= end; i++)
        {
            if (inorder[i] == root->data)
            {
                div = i;
                break;
            }
        }

        // Recurse to construct the left and right subtrees
        root->left = solve(inorder, preorder, str, div - 1);
        root->right = solve(inorder, preorder, div + 1, end);

        return root;
    }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder)
    {
        // code here
        pos = 0;
        return solve(inorder, preorder, 0, inorder.size() - 1); // pass inorder.size() - 1
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    vector<int> inorder = {3, 1, 4, 0, 2, 5};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};

    Solution obj;
    Node* root = obj.buildTree(inorder, preorder);

    printPostOrder(root);

    return 0;
}