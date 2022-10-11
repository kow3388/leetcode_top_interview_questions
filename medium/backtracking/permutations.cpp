#include <bits/stdc++.h>

using namespace std;


//這個答案是對的，題目上寫可以return any order
//但上傳上去leetcode會因為順序不同而得到wrong anser
void dfs(vector<vector<int>> &ans, vector<int> &nums, int l, int r, int n)
{
    if(r >= n or l >= n)
        return;

    if(l == n - 1 and r == n - 1)
        if(count(ans.begin(), ans.end(), nums))
            return;
        else
            ans.push_back(nums);
    else
    {
        if(l == r)
            return;
        else
        {
            swap(nums[l], nums[r]);
            dfs(ans, nums, l+1, r, n);
            dfs(ans, nums, l, r+1, n);
            swap(nums[l], nums[r]);
            dfs(ans, nums, l+1, r, n);
            dfs(ans, nums, l, r+1, n);
        }
    }
}

vector<vector<int>> permute1(vector<int> &nums)
{
    if(nums.size() == 1)
        return {nums};
    else
    {
        vector<vector<int>> ans;
        int n = nums.size();

        dfs(ans, nums, 0, 1, n);

        return ans;
    }
}

//用一個vector紀錄那些數字被使用過
//沒被使用過就塞進去
//d是紀錄目前的長度
void DFS(vector<vector<int>> &ans, vector<int> &nums, vector<int> &path, vector<int> &used, int d, int n)
{
    if(d == n)
        ans.push_back(path);
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(used[i])
                continue;
            used[i] = 1;
            path.push_back(nums[i]);
            DFS(ans, nums, path, used, d+1, n);
            path.pop_back();
            used[i] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    if(nums.size() == 1)
        return {nums};
    else
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> used(n);
        vector<int> path;

        DFS(ans, nums, path, used, 0, n);

        return ans;
    }
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permute(nums);

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}