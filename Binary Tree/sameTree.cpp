#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Level Order Traversal used
bool isSameTree(TreeNode *p, TreeNode *q)
{
    // T.C - O(N)
    // S.C - O(N)
    queue<TreeNode *> queue;
    queue.push(p);
    queue.push(q);

    while (!queue.empty())
    {
        TreeNode *first = queue.front();
        queue.pop();
        TreeNode *second = queue.front();
        queue.pop();

        // check for equality
        if (first == NULL && second == NULL)
        {
            continue;
        }
        else if (first == NULL || second == NULL || first->val != second->val)
        {
            return false;
        }

        queue.push(first->left);
        queue.push(second->left);
        queue.push(first->right);
        queue.push(second->right);
    }

    return true;
}

// Recursive Approach
bool isSameTree2(TreeNode *p, TreeNode *q)
{
    if (p == NULL || q == NULL)
    {
        return (p == q);
    }
    // T.C - O(N)
    // S.C - O(N)
    return (p->val == q->val) && isSameTree2(p->left, q->left) && isSameTree2(p->right, q->right);
}

int main()
{
    // Create a symmetric binary tree
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    // root1->right = new TreeNode(3);
    // root1->left->left = new TreeNode(3);
    // root1->left->right = new TreeNode(4);
    // root1->right->left = new TreeNode(4);
    // root1->right->right = new TreeNode(3);

    // Create a non-symmetric binary tree
    TreeNode *root2 = new TreeNode(1);
    // root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    // root2->left->right = new TreeNode(3);
    // root2->right->right = new TreeNode(3);

    cout << isSameTree(root1, root2);

    return 0;
}
