#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/mirror-tree/1

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    Node *solve(Node *node)
    {
        if (node == NULL)
            return NULL;

        Node *mirroredLeft = solve(node->left);
        Node *mirroredRight = solve(node->right);
        node->left = mirroredRight;
        node->right = mirroredLeft;

        return node;
    }
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node *node)
    {
        // code here
        node = solve(node);
    }
};

// Function to print tree in level-order (optional, for visualization).
void printLevelOrder(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node)
        {
            std::cout << node->data << " ";
            q.push(node->left);
            q.push(node->right);
        }
        else
        {
            cout << "null ";
        }
    }
    cout << endl;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);

    printLevelOrder(root);

    cout << '\n';

    Solution obj;
    obj.mirror(root);

    printLevelOrder(root);

    return 0;
}