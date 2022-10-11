#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* createnode(int data)
{
    TreeNode *tmp = new TreeNode();
    
    tmp->val = data;
    tmp->left = tmp->right = NULL;

    return tmp;
}

TreeNode* build(vector<int> &nums, int l, int h)
{
    if(l == h)
        return NULL;
    else
    {
        int half = (l + h)/2;
        TreeNode *root = createnode(nums[half]);
        root->left = build(nums, l, half);
        root->right = build(nums, half + 1, h);

        return root;
    }
}

TreeNode* sortedArrayToBST_2(vector<int> &nums)
{
    return build(nums, 0, nums.size());
}

TreeNode* sortedArrayToBST(vector<int> &nums)
{
    if(nums.empty())
        return NULL;
    else if(nums.size() == 1)
    {
        TreeNode *root = createnode(nums[0]);

        return root;
    }
    else
    {
        int half = nums.size()/2;
        TreeNode *root = createnode(nums[half]);
        vector<int> half1(nums.begin(), nums.begin() + half);
        vector<int> half2(nums.begin() + half + 1, nums.end());

        root->left = sortedArrayToBST(half1);
        root->right = sortedArrayToBST(half2);

        return root;
    }
}

vector<vector<int>> levelorder(TreeNode *root)
{
    if(!root)
        return {};
    else
    {
        vector<vector<int>> ans;
        vector<TreeNode*> curr, next;

        curr.push_back(root);

        while(!curr.empty())
        {
            ans.push_back({});
            for(TreeNode *tmp : curr)
            {
                ans.back().push_back(tmp->val);
                if(tmp->left)
                    next.push_back(tmp->left);
                if(tmp->right)
                    next.push_back(tmp->right);
            }
            curr.swap(next);
            next.clear();
        }

        return ans;
    }
}

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *root = sortedArrayToBST(nums);

    vector<vector<int>> ans = levelorder(root);

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}