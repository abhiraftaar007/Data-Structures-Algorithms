#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-two-sorted-lists/submissions/1506100321/?envType=study-plan-v2&envId=top-interview-150

// Define ListNode class
class ListNode
{
public:
    int val;
    ListNode *next;

    // Constructor to initialize node
    ListNode(int x) : val(x), next(nullptr) {}
};

// Approach 1 - Brute Force using space
ListNode *insertEnd(ListNode *root, int item)
{
    ListNode *temp = new ListNode(item);
    if (root == NULL)
        return temp;

    ListNode *last = root;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = temp;
    return root;
}

ListNode *arrayToList(vector<int> &arr, int n)
{
    ListNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insertEnd(root, arr[i]);
    }
    return root;
}

ListNode *mergeTwoLists1(ListNode *list1, ListNode *list2)
{
    // Brute Force
    // T.C - O(list1 size) + O(list2 size) + O(nlogn) + O(n)
    // S.C - O(N)
    vector<int> arr;
    ListNode *temp1 = list1;
    ListNode *temp2 = list2;

    while (temp1 != NULL)
    {
        arr.push_back(temp1->val);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        arr.push_back(temp2->val);
        temp2 = temp2->next;
    }

    sort(arr.begin(), arr.end());

    ListNode *result = arrayToList(arr, arr.size());
    return result;
}

// Approach 2 - Recursion
ListNode *mergeTwoLists2(ListNode *list1, ListNode *list2)
{
    // Using recursion
    if (list1 == NULL)
        return list2;

    if (list2 == NULL)
        return list1;

    ListNode *result;
    if (list1->val < list2->val)
    {
        result = list1;
        result->next = mergeTwoLists2(list1->next, list2);
    }
    else
    {
        result = list2;
        result->next = mergeTwoLists2(list1, list2->next);
    }

    return result;
}

// Approach 3 - using two pointers
ListNode *mergeTwoLists3(ListNode *list1, ListNode *list2)
{
    // Optimised using dummy node concept
    // T.C - O(N1 + N2)
    // S.C - O(1)
    ListNode *t1 = list1;
    ListNode *t2 = list2;
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->val < t2->val)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

    if (t1)
        temp->next = t1;
    else
        temp->next = t2;

    return dummyNode->next;
}

// Function to print the list
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    ListNode *mergedList = mergeTwoLists3(list1, list2);
    printList(mergedList);

    return 0;
}