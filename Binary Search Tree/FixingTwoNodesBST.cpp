#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    Node *first, *middle, *last, *prev;

    Solution()
    {
        first = middle = last = prev = NULL;
    }

    void correctBST(Node *root)
    {
        inorder(root);

        // If two nodes are swapped
        if (first && last)
        {
            // Swap data of first and last nodes
            int tmp = first->data;
            first->data = last->data;
            last->data = tmp;
        }
        // If only one node is swapped
        else if (first && middle)
        {
            // Swap data of first and middle nodes
            int tmp = first->data;
            first->data = middle->data;
            middle->data = tmp;
        }
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);

        // Identify the nodes that are swapped
        if (prev != NULL && prev->data > root->data)
        {
            // First violation
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            // Second violation (if any)
            else
            {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }
};

int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(20);

    Solution obj;

    obj.correctBST(root);

    cout << root->right->data;


    return 0;
}