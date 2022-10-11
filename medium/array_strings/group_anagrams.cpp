#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

//自己沒寫出來
//use hash table to solve
//把string sort之後塞入hash table最後把hash table的東西分別塞入vector
vector<vector<string>> groupAnagrams(vector<string> strs)
{
    vector<vector<string>> ans;
    unordered_map<string, vector<int>> index;

    if(strs.size() == 1)
    {
        ans.push_back(strs);
        return ans;
    }
    else
    {
        for(int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            index[str].push_back(i);
        }

        for(const auto &idx : index)
        {
            ans.push_back({});
            for(int i : idx.second)
                ans.back().push_back(strs[i]);
        }

        return ans;
    }
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans;

    ans = groupAnagrams(strs);

    return 0;
}