#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//BFS
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if(!root)
        return {};
    else
    {
        int cnt = 0;
        stack<TreeNode*> level, level_tmp;
        vector<vector<int>> ans;
        vector<int> ans_tmp;

        level.push(root);

        while(!level.empty())
        {
            TreeNode *tmp = level.top();
            level.pop();
            ans_tmp.push_back(tmp->val);
            if(cnt%2 == 0)
            {
                if(tmp->left)
                    level_tmp.push(tmp->left);
                if(tmp->right)
                    level_tmp.push(tmp->right);
            }
            else
            {
                if(tmp->right)
                    level_tmp.push(tmp->right);
                if(tmp->left)
                    level_tmp.push(tmp->left);
            }
            
            if(level.empty())
            {
                swap(level, level_tmp);
                cnt++;
                ans.push_back(ans_tmp);
                ans_tmp.clear();
            }
        }

        return ans;
    }
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(8);
    root->right->right->right->left = new TreeNode(7);

    vector<vector<int>> ans = zigzagLevelOrder(root);

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
/*
    3
1       5
   2  4     6
               8
            7
*/