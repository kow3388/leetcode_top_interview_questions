#include <bits/stdc++.h>

using namespace std;

//稍微看了一下想法寫出來
//用sliding windows
//先依照每組的第一個值sort
//然後sliding windows看
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(
        intervals.begin(),
        intervals.end(),
        [](const vector<int> &a, const vector<int> &b)
        {
            return a[0] < b[0];
        }
    );

    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++)
    {
        if(ans.back()[1] < intervals[i][0])
            ans.push_back(intervals[i]);
        else
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1,4}, {2,3}};
    vector<vector<int>> ans = merge(intervals);

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}