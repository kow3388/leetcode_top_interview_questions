#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};


//設一個快pointer和慢pointer, 如果快的跟慢的到同一個位置，則有cycle
bool hasCycle(ListNode *head)
{
    if(head == NULL or head->next == NULL)
        return false;
    else
    {
        ListNode *slow = head, *fast = head;
        
        //fast->next != 0 確保沒有環
        while(fast and fast->next)
        {   
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow)
                return true;
        }

        return false;
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

    ListNode *tmp = head->next;
    ListNode *ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = tmp;

    bool ans = hasCycle(head);

    cout << ans << endl;

    return 0;
}