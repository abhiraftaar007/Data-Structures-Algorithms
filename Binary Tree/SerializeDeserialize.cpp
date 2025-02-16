#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

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
    void preorder(Node *root, vector<int> &ans)
    {
        if (!root)
        {
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->data);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        // Your code here
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    int i = 0;

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr)
    {
        // Your code here
        int val = arr[i];
        i++;
        if (val == -1)
            return NULL;
        Node *nn = new Node(val);
        nn->left = deSerialize(arr);
        nn->right = deSerialize(arr);
        return nn;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Solution obj;

    vector<int> ans = obj.serialize(root);

    for (auto &i : ans)
    {
        cout << i << " ";
    }

    cout << '\n';

    Node *temp = obj.deSerialize(ans);
    cout << temp->data << '\n';
    cout << temp->left->data << '\n';
    cout << temp->right->data << '\n';

    return 0;
}