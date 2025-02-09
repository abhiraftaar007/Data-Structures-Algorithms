#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1

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
    int solve(Node *root, int &maxi)
    {
        if (!root)
            return 0;
        int leftSum = solve(root->left, maxi);
        int rightSum = solve(root->right, maxi);
        if (leftSum > 0 && rightSum > 0)
            maxi = max(maxi, root->data + leftSum + rightSum);
        else if (leftSum < 0 && rightSum < 0)
            maxi = max(maxi, root->data);
        else
            maxi = max(maxi, root->data + max(leftSum, rightSum));

        return max(0, root->data + max(leftSum, rightSum));
    }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root)
    {
        // code here
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};

int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->left->left = new Node(20);
    root->left->right = new Node(1);

    root->right = new Node(10);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    Solution obj;

    cout << obj.findMaxSum(root);

    return 0;
}