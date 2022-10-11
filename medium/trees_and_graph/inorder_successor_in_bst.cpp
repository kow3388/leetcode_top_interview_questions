#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode *root, vector<TreeNode*> &in_list)
{
    if(!root)
        return;
    else
    {
        inorder(root->left, in_list);
        in_list.push_back(root);
        inorder(root->right, in_list);
    }
}

TreeNode* inorderSuccessor(TreeNode *root, TreeNode *p)
{
    vector<TreeNode*> in_list;

    inorder(root, in_list);
    auto it = find(in_list.begin(), in_list.end(), p);

    if(it+1 == in_list.end())
        return nullptr;
    else
        return *(it+1);
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    TreeNode *tmp = root->right;

    TreeNode *ans = inorderSuccessor(root, tmp);

    cout << ans->val << endl;

    return 0;
}