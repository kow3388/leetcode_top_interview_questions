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

vector<vector<int>> LevelOrder(TreeNode *root)
{
    if(!root)
        return {};
    else
    {
        stack<TreeNode*> level, level_tmp;
        vector<vector<int>> ans;
        vector<int> ans_tmp;

        level.push(root);

        while(!level.empty())
        {
            TreeNode *tmp = level.top();
            level.pop();
            ans_tmp.push_back(tmp->val);

            if(tmp->left)
                    level_tmp.push(tmp->left);
            if(tmp->right)
                    level_tmp.push(tmp->right);
            
            if(level.empty())
            {
                swap(level, level_tmp);
                ans.push_back(ans_tmp);
                ans_tmp.clear();
            }
        }

        return ans;
    }
}

void inorder(TreeNode *root, int &cnt, int k, int &ans)
{
    if(root->left)
        inorder(root->left, cnt, k, ans);
    cnt++;
    if(cnt == k)
        ans = root->val;
    else
        if(root->right)
            inorder(root->right, cnt, k, ans);
}

int kthSmallest(TreeNode* root, int k)
{
    int cnt = 0;
    int ans = -1;
    inorder(root, cnt, k, ans);

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int ans = kthSmallest(root, 1);

    cout << ans << endl;

    return 0;
}