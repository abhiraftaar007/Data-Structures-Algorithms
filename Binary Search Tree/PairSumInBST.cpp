#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

class Node
{
    public:

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
    bool findTarget(Node *root, int target)
    {
        // your code here.
        if (root == NULL)
            return false;

        return solve(root, root, target);
    }

    bool solve(Node *root, Node *curr, int target)
    {
        if (curr == NULL)
            return false;
        if (findNode(root, target - curr->data, curr))
        {
            return true;
        }

        return solve(root, curr->left, target) || solve(root, curr->right, target);
    }

    bool findNode(Node *root, int target, Node *curr)
    {
        if (root == NULL)
            return false;
        if (root->data == target && root != curr)
            return true;

        if (root->data > target)
            return findNode(root->left, target, curr);

        return findNode(root->right, target, curr);
    }
};

int main()
{
    Node* root = new Node(7);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(8);
    root->right->right = new Node(9);

    int target = 12;

    Solution obj;
    cout << obj.findTarget(root, target);

    return 0;
}