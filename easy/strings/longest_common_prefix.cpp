#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if(strs.size() == 1)
        return strs[0];
    else
    {
        string ans;

        for(int i = 0; i < strs[0].length(); i++)
        {
            for(int j = 1; j < strs.size(); j++)
            {
                if(strs[0][i] != strs[j][i])
                    return ans;
            }
            ans.push_back(strs[0][i]);
        }
        return ans;
    }
}

int main()
{
    vector<string> strs = {"flower","flow","flight"};
    string ans;

    ans = longestCommonPrefix(strs);
    cout << ans << endl;
    
    return 0;
}