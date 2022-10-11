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

ListNode* createList(vector<int> nums)
{
    ListNode dummy(0);
    ListNode *head = &dummy;

    for(int i = 0; i < nums.size(); i++)
    {
        head->next = new ListNode(nums[i]);
        head = head->next;
    }

    return dummy.next;
}

ListNode* oddEvenList(ListNode *head)
{
    ListNode *odd_head, *odd_tail;
    ListNode *even_head, *even_tail;
    odd_head = head;
    if(!odd_head)
        return NULL;
    else
    {
        even_head = odd_head->next;
        even_tail = even_head;
    }
    
    if(!even_head)
        return head;
    else
        odd_tail = even_tail->next;

    while(even_tail and odd_tail)
    {
        even_tail->next = odd_tail->next;
        odd_tail->next = even_head;
        odd_head->next = odd_tail;
        even_tail = even_tail->next;
        odd_head = odd_tail;
        if(even_tail)
            odd_tail = even_tail->next;
    }

    return head;
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7, 8};
    ListNode *head = createList(nums);

    ListNode *ans = oddEvenList(head);
    while(ans != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;

    return 0;
}