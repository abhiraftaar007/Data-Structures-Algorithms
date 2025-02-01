#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/level-order-traversal/1

// A binary tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Using Stack (Recursive) Solution

vector<vector<int>> levelOrderRecursive(Node *root, int level, vector<vector<int>> &ans)
{
    // Base case: If node is null, return
    if (root == NULL)
        return {};

    // Add a new level to the result if needed
    if (ans.size() <= level)
    {
        ans.push_back({});
    }

    // Add current node's data to its corresponding level
    ans[level].push_back(root->data);

    // Recur for left and right children
    levelOrderRecursive(root->left, level + 1, ans);
    levelOrderRecursive(root->right, level + 1, ans);

    return ans;
}

// Level Order Traversal - Using Queue - Iterative Solution
vector<vector<int>> levelOrder(Node *root)
{
    // Your code here
    // T.C - O(N), S.C - O(N)

    if (root == NULL)
        return {};
    vector<vector<int>> ans;

    // Create an empty queue for level order traversal
    queue<Node *> q;
    q.push(root); // Enqueue Root

    int level = 0;

    while (!q.empty())
    {
        int len = q.size();
        ans.push_back({});

        for (int i = 0; i < len; i++)
        {
            // Add front of queue and remove it from queue
            Node *newNode = q.front();
            q.pop();

            ans[level].push_back(newNode->data);

            // Enqueue left child
            if (newNode->left != NULL)
            {
                q.push(newNode->left);
            }

            // Enqueue right child
            if (newNode->right != NULL)
            {
                q.push(newNode->right);
            }
        }

        level++;
    }

    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->right = new Node(4);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(5);

    // vector<vector<int>> result = levelOrder(root);

    vector<vector<int>> ans;
    vector<vector<int>> result = levelOrderRecursive(root, 0, ans);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}