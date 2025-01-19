#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

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

Node *rotate(Node *head, int k)
{
    // Your code here
    // Self-solution
    if (head->next == NULL || head == NULL)
    {
        return head;
    }

    Node *temp = head;
    int len = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }

    int idx = k % len;
    if (idx == 0)
        return head;

    Node *prev = NULL;
    Node *cur = head;
    int cnt = 1;

    while (cnt <= idx)
    {
        prev = cur;
        cur = cur->next;
        cnt++;
    }
    prev->next = NULL;
    Node *newHead = cur;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = head;

    return newHead;
}

void insertEnd(Node *&head, int value)
{
    Node *newNode = new Node(value);
    // newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node* root = new Node(10);
    insertEnd(root, 20);
    insertEnd(root, 30);
    insertEnd(root, 40);

    int k = 6;

    printList(root);

    cout << endl;

    root = rotate(root, k);

    printList(root);
    
    return 0;
}