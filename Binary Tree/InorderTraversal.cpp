#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/inorder-traversal/1

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
    vector<int> ans;
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node *root)
    {
        // Your code here
        if (root == NULL)
            return {};

        inOrder(root->left);

        ans.push_back(root->data);

        inOrder(root->right);

        return ans;
    }
};

int main()
{
    Node* root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;

    vector<int> ans = obj.inOrder(root);

    for(auto& i:ans){
        cout << i << " ";
    }
    
    return 0;
}