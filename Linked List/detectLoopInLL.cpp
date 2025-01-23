#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

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

// Solution 1
bool detectLoop(Node *head)
{
    // because - 1 ≤ node->data ≤ 10^3
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            return true;
        temp->data = 0;
        temp = temp->next;
    }

    return false;
}

// Solution 2
bool detectLoop2(Node *head)
{
    // your code here
    // Tortoise and Hare Algorithm
    // floyd's cycle finding algorithm
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }

    return false;
}

int main()
{
    Node* a = new Node(1);
    a->next = new Node(3);
    a->next->next = new Node(4);
    a->next->next->next = a->next;

    cout << detectLoop2(a);

    return 0;
}