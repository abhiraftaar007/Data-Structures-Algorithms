#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/path-sum-iii/description/?envType=study-plan-v2&envId=leetcode-75

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int pathSum_a(TreeNode *root, long long sum)
{
    if (root == nullptr)
        return 0;

    int res = 0;

    // If the current node's value is equal to the remaining sum, increase the count
    if (root->val == sum)
        res++;

    // Continue searching in the left and right subtrees, reducing the sum
    res += pathSum_a(root->left, sum - root->val);
    res += pathSum_a(root->right, sum - root->val);

    return res;
}

int pathSum(TreeNode *root, int sum)
{
    if (root == nullptr)
        return 0;

    // Cast sum to long long for safety
    long long long_sum = sum;

    // Count paths starting from the root (with pathSum_a)
    int res = pathSum_a(root, long_sum);

    // Recursively count paths in the left and right subtrees that start from any node
    res += pathSum(root->left, long_sum);
    res += pathSum(root->right, long_sum);

    return res;
}

// Function to insert nodes into the binary tree.
TreeNode *insertLevelOrder(const std::vector<int> &values, int i)
{
    if (i >= values.size() || values[i] == -1)
    {
        return nullptr;
    }
    TreeNode *node = new TreeNode(values[i]);
    node->left = insertLevelOrder(values, 2 * i + 1);
    node->right = insertLevelOrder(values, 2 * i + 2);
    return node;
}

// Function to print tree in level-order (optional, for visualization).
void printLevelOrder(TreeNode *root)
{
    if (root == nullptr)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node)
        {
            std::cout << node->val << " ";
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
    // Representing the binary tree as a vector.
    std::vector<int> values = {10, 5, -3, 3, 2, -1, 11, 3, -2, -1, 1};

    // Constructing the tree from the given values.
    TreeNode *root = insertLevelOrder(values, 0);
    int target = 8;

    // Printing the tree using level-order traversal (optional).
    std::cout << "Binary Tree in Level-Order: ";
    // printLevelOrder(root);

    cout << endl;

    cout << pathSum(root, target);


    return 0;
}