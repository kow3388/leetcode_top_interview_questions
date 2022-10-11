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

//time: O(max(m, n)), space: O(max(m+n))
//我的方法其實在search hash table時會花時間
ListNode* getIntersectionNode1(ListNode *headA, ListNode *headB)
{
    unordered_map<ListNode*, int> table;
    ListNode *a = headA, *b = headB;
    int i = 0;

    while(a or b)
    {
        if(a)
        {
            if(table.count(a))
                return a;
            else
            {
                table[a] = i++;
                a = a->next;
            }
        }

        if(b)
        {
            if(table.count(b))
                return b;
            else
            {
                table[b] = i++;
                b = b->next;
            }
        }
    }

    return NULL;
}

//time: O(n+m), space: O(1)
ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB) return nullptr;
    ListNode* a = headA;
    ListNode* b = headB;

    //a走完會去走b，b走完會去走a，所以兩個人走的路徑會一樣多
    //如果有交集，兩個人在走對方的路線時，會相交在交點
    //如果沒有交集，則兩個人會同時走到NULL
    while (a != b) {
      a = a ? a->next : headB;
      b = b ? b->next : headA;
    }
    return a;
}

int main()
{
    vector<int> nums = {4,1};
    ListNode *headA = createList(nums);

    nums = {5, 6, 1};
    ListNode *headB = createList(nums);

    /*nums = {8, 4, 5};
    ListNode *headC = createList(nums);

    ListNode *tmp = headA;

    while(tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = headC;

    tmp = headB;

    while(tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = headC;*/

    ListNode *ans = getIntersectionNode(headA, headB);
    while(ans != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;

    return 0;
}