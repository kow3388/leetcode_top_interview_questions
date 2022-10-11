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

void inorder(TreeNode *root, vector<int> &ans)
{
    if(root->left)
        inorder(root->left, ans);
    ans.push_back(root->val);
    if(root->right)
        inorder(root->right, ans);
}

//LDR
vector<int> inorderTraversal(TreeNode *root)
{
    if(!root)
        return {};
    else
    {
        vector<int> ans;
        inorder(root, ans);

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

    vector<int> ans = inorderTraversal(root);

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}