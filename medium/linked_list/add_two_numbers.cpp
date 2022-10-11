#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers1(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode();
    ListNode *head = ans;

    int v1 = l1->val, v2 = l2->val;
    int value = (v1 + v2)%10;
    int carry = (v1 + v2)/10;

    head->val = value;
    l1 = l1->next;
    l2 = l2->next;

    while(l1 != NULL or l2 != NULL)
    {
        if(l1 == NULL)
            v1 = 0;
        else
            v1 = l1->val;
        if(l2 == NULL)
            v2 = 0;
        else
            v2 = l2->val;
        
        value = (v1 + v2 + carry)%10;
        carry = (v1 + v2 + carry)/10;

        ListNode *tmp = new ListNode(value);
        head->next = tmp;
        head = tmp;

        if(l1 != NULL)
            l1 = l1->next;
        if(l2 != NULL)
            l2 = l2->next;
    }

    if(carry != 0)
    {
        ListNode *tmp = new ListNode(1);
        head->next = tmp;
    }

    return ans;
}

//跟我的想法一樣，只是比我寫的有效率
ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode dummy(0);
    ListNode *head = &dummy;
    int sum = 0;

    while(l1 or l2 or sum)
    {
        sum += (l1? l1->val:0) + (l2? l2->val:0);
        l1 = l1? l1->next:NULL;
        l2 = l2? l2->next:NULL;
        head->next = new ListNode(sum % 10);

        sum /= 10;
        head = head->next;
    }

    return dummy.next;
}

int main()
{
    ListNode *l1 = new ListNode(9);
    ListNode *tmp1 = l1;
    int i = 0;

    while(i < 6)
    {
        ListNode *node = new ListNode(9);
        tmp1->next = node;
        tmp1 = tmp1->next;
        i++;
    }

    ListNode *l2 = new ListNode(9);
    ListNode *tmp2 = l2;
    i = 0;

    while(i < 3)
    {
        ListNode *node = new ListNode(9);
        tmp2->next = node;
        tmp2 = tmp2->next;
        i++;
    }

    ListNode *ans = addTwoNumbers(l1, l2);
    while(ans != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;

    return 0;
}