#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    vector<int> boundaryTraversal(Node *root)
    {
        // code here
        vector<int> ans;
        if (root->left != NULL || root->right != NULL)
        {
            ans.push_back(root->data);
        }
        leftNodes(root->left, ans);
        addLeaves(root, ans);
        rightRevNodes(root->right, ans);
        return ans;
    }

    void leftNodes(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (root->left != NULL)
        {
            ans.push_back(root->data);
            leftNodes(root->left, ans);
        }
        else if (root->right != NULL)
        {
            ans.push_back(root->data);
            leftNodes(root->right, ans);
        }
    }

    void addLeaves(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        addLeaves(root->left, ans);
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
        }

        addLeaves(root->right, ans);
    }

    void rightRevNodes(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->right != NULL)
        {
            rightRevNodes(root->right, ans);
            ans.push_back(root->data);
        }
        else if (root->left != NULL)
        {
            rightRevNodes(root->left, ans);
            ans.push_back(root->data);
        };
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;

    vector<int> ans = obj.boundaryTraversal(root);

    for (auto &i : ans)
    {
        cout << i << " ";
    }
    
    return 0;
}