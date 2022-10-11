#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

//time: O(n), space: O(n)
Node* connect1(Node *root)
{
    if(!root)
        return NULL;
    else
    {
        queue<Node*> q, q_tmp;
        q.push(root);

        while(!q.empty())
        {
            Node *tmp = q.front();
            q.pop();

            if(tmp->left)
                q_tmp.push(tmp->left);
            if(tmp->right)
                q_tmp.push(tmp->right);
            
            if(!q.empty())
                tmp->next = q.front();
            else
                swap(q, q_tmp);
        }

        return root;
    }
}

//time: O(n), space: O(1)
Node* connect(Node *root)
{
    if(!root or !root->left)
        return root;
    root->left->next = root->right;

    if(root->next)
        root->right->next = root->next->left;
    connect(root->left);
    connect(root->right);

    return root;
}

int main()
{   
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *ans = connect(root);
    while(ans)
    {
        Node *tmp = ans;
        while(tmp->next)
        {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << tmp->val << endl;
        ans = ans->left;
    }
    
    return 0;
}