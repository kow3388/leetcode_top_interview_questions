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

TreeNode* create(vector<int> &pre, vector<int> &in, int D, int start, int end)
{
    if(start == end)
    {
        TreeNode *root = new TreeNode(in[D]);
        return root;
    }
    else
    {
        TreeNode *root = new TreeNode(in[D]);
        int pre_D = distance(pre.begin(), find(pre.begin(), pre.end(), in[D]));
        //have left subtree
        if(D != start)
        {
            int l_D = distance(in.begin(), find(in.begin(), in.end(), pre[pre_D+1]));
            root->left = create(pre, in, l_D, start, D-1);
        }
        //have right subtree
        if(D != end)
        {
            int r_D = distance(in.begin(), find(in.begin(), in.end(), pre[pre_D+(D-start)+1]));
            root->right = create(pre, in, r_D, D+1, end);
        }
        return root;
    }
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
{
        int n = inorder.size();
        int D = distance(inorder.begin(), find(inorder.begin(), inorder.end(), preorder[0]));
        TreeNode *root = create(preorder, inorder, D, 0, n-1);

        return root;
}

int main()
{
    vector<int> preorder = {3,9,20,15,7};   //DLR
    vector<int> inorder = {9,3,15,20,7};    //LDR

    TreeNode *root = buildTree(preorder, inorder);
    vector<vector<int>> ans = LevelOrder(root);

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}