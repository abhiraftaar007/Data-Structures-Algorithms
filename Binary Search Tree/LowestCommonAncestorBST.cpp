#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

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
    Node *LCA(Node *root, Node *n1, Node *n2)
    {
        // code here
        return solve(root, min(n1->data, n2->data), max(n1->data, n2->data));
    }

    Node *solve(Node *root, int n1, int n2)
    {
        if (root == NULL)
            return root;

        if ((n1 < root->data && n2 > root->data) || root->data == n1 || root->data == n2)
        {
            return root;
        }

        if (n2 < root->data)
        {
            return solve(root->left, n1, n2);
        }

        return solve(root->right, n1, n2);
    }
};

int main()
{
    Node* root = new Node(5);
    root->left = new Node(4);
    root->left->left = new Node(3);
    root->right = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);

    Node* n1 = new Node(7);
    Node* n2 = new Node(8);

    Solution obj;

    Node* ans = obj.LCA(root,n1,n2);

    cout << ans->data;

    return 0;
}