#include <bits/stdc++.h>

using namespace std;

//用白癡方法解，把兩個問題的方法結合在一起
bool check(string s)
{
    stack<char> p_stack;

    for(const char c : s)
    {
        if(c == '(')
            p_stack.push(c);
        else
        {
            if(p_stack.empty())
                return false;
            else if(p_stack.top() != '(')
                return false;
            else
                p_stack.pop();
        }
    }

    if(!p_stack.empty())
        return false;
    else
        return true;
}

void dfs(vector<string> &ans, string &tmp, vector<char> &p, int n, int l)
{
    if(l == n)
    {
        if(check(tmp))
            ans.push_back(tmp);
    }
    else
    {
        for(const char c : p)
        {
            tmp.push_back(c);
            dfs(ans, tmp, p, n, l+1);
            tmp.pop_back();
        }
    }
}

vector<string> generateParenthesis1(int n)
{
    if(n == 1)
        return {"()"};
    else
    {
        vector<string> ans;
        vector<char> p = {'(', ')'};
        string tmp = "(";
        int num = 2*n-1;

        dfs(ans, tmp, p, num, 0);

        return ans;
    }
}

void DFS(vector<string> &ans, string &s, int l, int r)
{
    if(l + r == 0)
        ans.push_back(s);
    else
    {
        //強制讓第一個一定是(
        if(r < l)
            return;
        if(l > 0)
        {
            DFS(ans, s += "(", l - 1, r);
            s.pop_back();
        }
        if(r > 0)
        {
            DFS(ans, s += ")", l, r - 1);
            s.pop_back();
        }
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string s;
    if(n > 0)
        DFS(ans, s, n, n);
    return ans;
}

int main()
{
    int n = 3;
    vector<string> ans = generateParenthesis(n);

    for(const string s : ans)
        cout << s << endl;
    
    return 0;
}