#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Floyd's Cycle Finding Algorithm 
// T.C - O(N)
// S.C - O(1)
Node *findFirstNode(Node *head)
{
    // your code here

    // Initialize two pointers, slow and fast
    Node *slow = head;
    Node *fast = head;

    // Traverse the list
    while (fast != nullptr && fast->next != nullptr)
    {

        // Move slow pointer by one step
        slow = slow->next;

        // Move fast pointer by two steps
        fast = fast->next->next;

        // Detect loop
        if (slow == fast)
        {

            // Move slow to head, keep fast at meeting point
            slow = head;

            // Move both one step at a time until they meet
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            // Return the meeting node, which
            // is the start of the loop
            return slow;
        }
    }

    // No loop found
    // return nullptr;
    return new Node(-1);
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next;

    Node *ans = findFirstNode(head);

    cout << ans->data;

    return 0;
}