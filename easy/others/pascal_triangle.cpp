#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    if(numRows == 1)
        return {{1}};
    else
    {
        vector<vector<int>> ans = {{1}};
        for(int i = 1; i < numRows; i++)
        {
            vector<int> tmp;
            tmp.push_back(1);
            for(int j = 0; j < ans[i - 1].size() - 1; j++)
            {
                tmp.push_back(ans[i-1][j] + ans[i-1][j+1]);
            }
            tmp.push_back(1);
            ans.push_back(tmp);
        }

        return ans;
    }
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = generate(n);

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}