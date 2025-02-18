#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-linked-list-elements/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // self-solution
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return head;

        ListNode *newHead = head;

        while (newHead != NULL)
        {
            if (newHead->val != val)
                break;
            newHead = newHead->next;
        }

        ListNode *curr = newHead;
        ListNode *prev = new ListNode(-1);

        while (curr != NULL)
        {
            if (curr->val == val)
            {
                prev->next = curr->next;
                curr = prev->next;
                continue;
            }

            prev = curr;
            curr = curr->next;
        }

        return newHead;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int val = 6;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution obj;
    head = obj.removeElements(head, val);

    ListNode* temp = head;

    while(temp!=NULL){
        cout << temp->val <<  " ";
        temp = temp->next;
    }


    return 0;
}