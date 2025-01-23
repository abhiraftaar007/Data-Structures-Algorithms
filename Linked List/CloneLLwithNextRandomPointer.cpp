#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

Node *cloneLinkedList(Node *head)
{
    // Write your code here
    if (head == NULL)
    {
        return NULL;
    }

    Node *curr = head;
    while (curr != NULL)
    {
        Node *copy = new Node(curr->data);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }

    curr = head;
    while (curr != NULL)
    {
        if (curr->random != NULL)
        {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    curr = head;
    Node *copyH = head->next;

    while (curr != NULL)
    {
        Node *copy = curr->next;
        curr->next = copy->next;
        if (copy->next != NULL)
        {
            copy->next = copy->next->next;
        }

        curr = curr->next;
    }

    return copyH;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << "Data: " << head->data;
        if (head->random)
        {
            cout << ", Random points to: " << head->random->data;
        }
        else
        {
            cout << ", Random points to: NULL";
        }
        cout << endl;
        head = head->next;
    }
}

int main()
{
    // Create a linked list with next and random pointers
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(9);

    head->random = head->next->next;                   // 1's random points to 5
    head->next->random = head->next->next;             // 3's random points to 5
    head->next->next->random = NULL;                   // 5's random points to NULL
    head->next->next->next->random = head->next->next; // 9's random points to 5

    cout << "Original List:" << endl;
    printList(head);

    Node *clonedHead = cloneLinkedList(head);

    cout << "\nCloned List:" << endl;
    printList(clonedHead);
    return 0;
}