#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode* mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if(list1 == NULL and list2 == NULL)
        return NULL;
    else if(list1 == NULL and list2 != NULL)
        return list2;
    else if(list1 != NULL and list2 == NULL)
        return list1;
    else
    {
        ListNode *head = new ListNode();
        ListNode *ans = head;
        head->next = NULL;

        if(list1->val > list2->val)
        {
            head->val = list2->val;
            list2 = list2->next;
        }
        else
        {
            head->val = list1->val;
            list1 = list1->next;
        }
        
        while(list1 != NULL and list2 != NULL)
        {
            if(list1->val > list2->val)
            {
                head->next = list2;
                head = head->next;
                list2 = list2->next;
            }
            else
            {
                head->next = list1;
                head = head->next;
                list1 = list1->next;
            }
        }

        while(list1 != NULL)
        {
            head->next = list1;
            head = head->next;
            list1 = list1->next;
        }

        while(list2 != NULL)
        {
            head->next = list2;
            head = head->next;
            list2 = list2->next;
        }

        return ans;
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
    ListNode *list1 = NULL, *list2 = NULL;
    add_node(&list1, 1);
    add_node(&list1, 2);
    add_node(&list1, 4);
    add_node(&list2, 1);
    add_node(&list2, 3);
    add_node(&list2, 4);

    ListNode *tmp = mergeTwoLists(list1, list2);

    while(tmp != NULL)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}