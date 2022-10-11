#include <bits/stdc++.h>

using namespace std;

//自己沒想到
//dfs的概念，一直往下找
void combination(string &s, vector<vector<char>> &d, vector<string> &ans, string &tmp, int l)
{
    if(l == s.length())
    {
        ans.push_back(tmp);
        return;
    }
    else
    {
        for(const char c : d[s[l] - '0'])
        {
            tmp.push_back(c);
            combination(s, d, ans, tmp, l+1);
            tmp.pop_back();
        }
    }
}

vector<string> letterCombinations(string digits)
{
    int n = digits.length();
    
    if(n == 0)
        return {};
    else
    {
        vector<vector<char>> d(10);
        d[0] = {' '};
        d[1] = {};
        d[2] = {'a','b','c'};
        d[3] = {'d','e','f'};
        d[4] = {'g','h','i'};
        d[5] = {'j','k','l'};
        d[6] = {'m','n','o'};
        d[7] = {'p','q','r','s'};
        d[8] = {'t','u','v'};
        d[9] = {'w','x','y','z'};

        vector<string> ans;
        string ans_tmp;

        combination(digits, d, ans, ans_tmp, 0);

        return ans;
    }
}

int main()
{
    string digits = "23";
    vector<string> ans = letterCombinations(digits);

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}