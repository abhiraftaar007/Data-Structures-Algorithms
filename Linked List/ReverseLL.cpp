#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// Space used
Node *reverseList1(struct Node *head)
{
    // code here
    Node *temp = head;
    vector<int> arr;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int n = arr.size() - 1;
    Node *head1 = new Node();
    head1->data = arr[n--];

    temp = head1;
    while (n >= 0)
    {
        temp->next = new Node();
        temp->next->data = arr[n];
        temp = temp->next;
        n--;
    }

    return head1;
}

// Recursive Solution
Node *reverseList2(struct Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *newHead = reverseList2(head->next);
    Node *headNext = head->next;
    headNext->next = head;
    head->next = nullptr;

    return newHead;
}

Node *reverseList3(struct Node *head)
{
    // code here
    // CHATGPT Code
    Node *prev = nullptr;
    Node *current = head;

    // Traverse the original list and reverse the links
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // After the loop, 'prev' will be pointing to the new head
    return prev;
}

// Function to insert a new node at the end of the linked list
void insertEnd(Node *&head, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
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
    Node *head = nullptr;

    // Inserting some elements into the list
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "Original List: ";
    printList(head);

    // Reversing the linked list
    head = reverseList3(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
