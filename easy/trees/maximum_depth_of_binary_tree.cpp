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

int maxDepth(TreeNode* root)
{
    if(root == NULL)
        return 0;
    else if(root->left == NULL and root->right == NULL)
        return 1;
    else
    {
        int left_depth = 1 + maxDepth(root->left);
        int right_depth = 1 + maxDepth(root->right);

        if(left_depth > right_depth)
            return left_depth;
        else
            return right_depth;
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

    int ans = maxDepth(root);
    
    cout << ans << endl;

    return 0;
}