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

bool check(TreeNode *root1, TreeNode *root2)
{
    if(!root1 and !root2)
        return true;
    else if(!root1 or !root2)
        return false;
    else
    {
        bool val_flag = (root1->val == root2->val)? 1 : 0;

        return val_flag && check(root1->left, root2->right) && check(root1->right, root2->left);
    }
}

bool isSymmetric(TreeNode *root)
{
    return check(root, root);
}

int main()
{
    TreeNode *root = NULL;

    root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(2);
    root->right->left = createnode(4);
    root->right->right = createnode(3);
    root->left->left = createnode(3);
    root->left->right = createnode(4);

    bool ans = isSymmetric(root);
    
    cout << ans << endl;

    return 0;
}