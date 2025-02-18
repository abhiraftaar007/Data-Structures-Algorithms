#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // self - solution
    Node *mergeKLists(vector<Node *> &arr)
    {
        // T.C - O(nlogn+n)
        // S.C - O(n)
        if (arr.size() == 0)
            return NULL;
        // Your code here
        vector<int> ele; // O(n)

        int n = arr.size();

        for (int i = 0; i < n; i++)
        { // O(n), number of nodes
            Node *head = arr[i];
            while (head != NULL)
            {
                ele.push_back(head->data);
                head = head->next;
            }
        }

        sort(ele.begin(), ele.end()); // O(nlogn)

        Node *head = new Node(ele[0]);

        int i = 1;
        n = ele.size();

        Node *temp = head;

        while (i < n)
        { // O(n)
            Node *newNode = new Node(ele[i]);
            temp->next = newNode;
            temp = temp->next;
            i++;
        }

        return head;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Node* one = new Node(1);
    one->next = new Node(3);

    Node* two = new Node(8);

    Node* three = new Node(4);
    three->next = new Node(5);
    three->next->next = new Node(6);

    vector<Node*> arr = {one, two, three};

    Solution obj;

    Node* ans = obj.mergeKLists(arr);

    while(ans!=NULL){
        cout << ans->data << " ";
        ans = ans->next;
    }

    return 0;
}