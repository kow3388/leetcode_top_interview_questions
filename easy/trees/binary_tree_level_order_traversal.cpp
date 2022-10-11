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

vector<vector<int>> levelOrder(TreeNode *root)
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
    TreeNode *root = NULL;

    root = createnode(3);
    root->left = createnode(9);
    root->right = createnode(20);
    root->right->left = createnode(15);
    root->right->right = createnode(7);

    vector<vector<int>> ans = levelOrder(root);

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}