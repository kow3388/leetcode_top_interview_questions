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

bool isvalidate(TreeNode *root, long min_val, long max_val)
{
    if(!root)
        return true;

    if(root->val <= min_val or root->val >= max_val)
        return false;
    else
    return isvalidate(root->left, min_val, root->val) && isvalidate(root->right, root->val, max_val);
}

bool isValidBST(TreeNode *root)
{
    return isvalidate(root, LLONG_MIN, LLONG_MAX);
}

int main()
{
    TreeNode *root = NULL;

    root = createnode(2);
    //root->left = createnode(2);
    root->right = createnode(2);
    /*root->right->left = createnode(6);
    root->right->right = createnode(8);*/

    bool ans = isValidBST(root);
    
    cout << ans << endl;

    return 0;
}