#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=study-plan-v2&envId=leetcode-75

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Using Space - self solution
int pairSum(ListNode *head)
{
    ListNode *temp = head;
    vector<int> arr;
    while (temp != NULL)
    {
        arr.push_back(temp->val);
        temp = temp->next;
    }
    int n = arr.size();
    int i = 0, j = n - 1;
    int ans = 0;

    while (i < j)
    {
        int sum = arr[i] + arr[j];
        ans = max(ans, sum);
        i++;
        j--;
    }

    return ans;
}

int main()
{
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    cout << pairSum(head);
    
    return 0;
}