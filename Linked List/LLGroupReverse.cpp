#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

// function to swap elements in the array
void swapp(int i, int j, vector<int> &arr)
{
    while (i <= j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

// Function to reverse the linked list in groups of k
// Brute Force - self solution
Node *reverseKGroup(Node *head, int k)
{
    // code here
    Node *temp = head;
    vector<int> arr;

    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int n = arr.size();
    int i = 0, j = 0;

    while (j < n)
    {
        int cnt = 0;
        while (j < n && cnt < k - 1)
        {
            if (j == n - 1)
                break;
            j++;
            cnt++;
        }
        int temp_i = i;
        int temp_j = j;
        swapp(temp_i, temp_j, arr);
        i = j + 1;
        j = i;
    }

    // Create a new linked list from the modified array
    Node *newHead = new Node(arr[0]);

    temp = newHead;

    i = 1;

    while (i < n)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
        i++;
    }

    return newHead;
}

// Function to reverse K groups
// Optimal solution - without space
Node *reverseKGroup2(Node *head, int k)
{
    if (head == nullptr)
    {
        return head;
    }

    Node *curr = head;
    Node *newHead = nullptr;
    Node *tail = nullptr;

    while (curr != nullptr)
    {
        Node *groupHead = curr;
        Node *prev = nullptr;
        Node *nextNode = nullptr;
        int count = 0;

        // Reverse the nodes in the current group
        while (curr != nullptr && count < k)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        // If newHead is null, set it to the
        // last node of the first group
        if (newHead == nullptr)
        {
            newHead = prev;
        }

        // Connect the previous group to the
        // current reversed group
        if (tail != nullptr)
        {
            tail->next = prev;
        }

        // Move tail to the end of the reversed group
        tail = groupHead;
    }

    return newHead;
}

// Helper function to create a linked list from an array
Node *createList(const vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

// Function to print the linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    Node* head = createList(arr);

    int k = 3;
    Node* newHead = reverseKGroup2(head, k);

    printList(newHead);

    return 0;
}