#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode* removeNthFromEnd(ListNode *head, int n)
{
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        ListNode *tmp1 = head, *tmp2 = head;
        for(int i = 0; i < n; i++)
            tmp1 = tmp1->next;
        
        if(tmp1 != NULL)
        {
            while(tmp1->next != NULL)
            {
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }

            ListNode *delete_node = tmp2->next;
            tmp2->next = tmp2->next->next;
            delete delete_node;
        }
        else
            head = head->next;

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
    /*add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);*/

    ListNode *tmp = removeNthFromEnd(head, 2);

    while(tmp != NULL)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}