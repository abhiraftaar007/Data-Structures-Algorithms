#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void removeLoop(Node *head)
{
    // code here
    Node *slow = head;
    Node *fast = head;
    Node *prev = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        prev = fast;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            prev = prev->next;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
                prev = prev->next;
            }

            prev->next = NULL;
            return;
        }
    }
}

// Function to print the linked list
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    removeLoop(head);

    printList(head);
    
    return 0;
}