#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

void deleteNode(ListNode *node)
{
    ListNode *tmp = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    delete tmp;
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
    add_node(&head, 4);
    add_node(&head, 5);
    add_node(&head, 1);
    add_node(&head, 9);

    head = head->next;

    deleteNode(head);

    return 0;
}