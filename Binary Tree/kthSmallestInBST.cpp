#include<bits/stdc++.h>
using namespace std;

// http://geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

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
    void inorder(Node *root, int &k, int &ans)
    {
        if (!root)
            return;
        inorder(root->left, k, ans);
        k--;
        if (k == 0)
        {
            ans = root->data;
            return;
        }

        inorder(root->right, k, ans);
    }
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k)
    {
        // add code here.
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};

int main()
{
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    Solution obj;
    int k = 2;

    cout << obj.kthSmallest(root,k);

    return 0;
}