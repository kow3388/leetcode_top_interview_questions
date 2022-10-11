#include <bits/stdc++.h>

using namespace std;

//我自己寫的
vector<vector<int>> subsets1(vector<int> &nums)
{
    if(nums.size() == 1)
        return {{}, nums};
    else
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> tmp;

        function<void(int)> DFS = [&] (int d)
        {
            if(d == n)
                ans.push_back(tmp);
            else
            {
                tmp.push_back(nums[d]);
                DFS(d+1);
                tmp.pop_back();
                DFS(d+1);
            }
        };
        DFS(0);

        return ans;
    }
}

//一樣是dfs
vector<vector<int>> subsets2(vector<int> &nums)
{
    if(nums.size() == 1)
        return {{}, nums};
    else
    {
        vector<vector<int>> ans;
        vector<int> tmp;

        //d表示我們要的subset大小, s是目前的subset大小
        function<void(int, int)> dfs = [&] (int d, int s)
        {
            if(d == tmp.size())
                ans.push_back(tmp);
            else
                for(int j = s; j < nums.size(); j++)
                {
                    tmp.push_back(nums[j]);
                    dfs(d, j+1);
                    tmp.pop_back();
                }
        };

        //我們要的subset大小從0到nums.size()
        for(int i = 0; i <= nums.size(); i++)
            dfs(i, 0);

        return ans;
    }
}

//用bits的方式來篩選subset
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;

    //1 << n 表示共用幾種可能
    //i (以bit表示) 表示此subset有哪些數
    //ex: i = 3, i = 011, 表示裡面有第0個數和第1個數
    for(int i = 0; i < 1 << n; i++)
    {
        cout << i << endl;
        vector<int> tmp;
        for(int j = 0; j < n; j++)
            if(i & (1 << j))
                tmp.push_back(nums[j]);
        ans.push_back(tmp);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsets(nums);

    /*for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }*/

    return 0;
}