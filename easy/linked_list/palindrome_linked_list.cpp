#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode* reverseList(ListNode *head)
{
    if(head == NULL or head->next == NULL)
        return head;
    else
    {
        ListNode *next_node = head->next;
        ListNode *prev_node = NULL;

        while(next_node != NULL)
        {
            head->next = prev_node;
            prev_node = head;
            head = next_node;
            next_node = head->next;
        }

        head->next = prev_node;

        return head;
    }
}

bool isPalindrome(ListNode *head)
{
    
    if(head->next == NULL)
        return true;
    else
    {
        ListNode *slow = head, *fast = head;

        //fast會走2n格(整個list) slow會走n格(半個list)
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //表示list為奇數
        if(fast)
            slow = slow->next;

        slow = reverseList(slow);

        while(slow != NULL)
        {
            if(slow->val != head->val)
                return false;
            else
            {
                slow = slow->next;
                head = head->next;
            }
        }

        return true;
    }
}

void add_node(ListNode **head, int v)
{
    ListNode *tmp = new ListNode();
    ListNode *i;
    
    tmp->val = v;
    tmp->next = NULL;
    if(*head == NULL)
        *head = tmp;
    else
    {
        i = *head;
        while(i->next != NULL)
            i = i->next;

        i->next = tmp;
    }
}

int main()
{
    ListNode *head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 3);
    add_node(&head, 1);

    bool ans = isPalindrome(head);
    cout << ans << endl;

    return 0;
}