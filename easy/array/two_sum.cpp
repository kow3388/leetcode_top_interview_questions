#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    if(nums.size() == 2)
        return {0, 1};
    else
    {
        unordered_map<int, int> map;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++)
        {
            if(map.count(nums[i]))
            {
                ans.push_back(map[nums[i]]);
                ans.push_back(i);
                break;
            }
            map[target - nums[i]] = i;
        }

        return ans;
    }
}

int main()
{
    vector<int> nums = {2,11,15,7};
    vector<int> ans;
    int target = 9;

    ans = twoSum(nums, target);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}