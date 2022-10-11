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
    add_node(&head, 4);
    add_node(&head, 5);

    ListNode *tmp = reverseList(head);

    while(tmp != NULL)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}