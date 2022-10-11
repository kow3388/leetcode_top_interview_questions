#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> threesum(vector<int> &nums)
{
    vector<int> three_sum(3);
    vector<vector<int>> ans;
    
    sort(nums.begin(), nums.end());
    
    int idx1, idx2, idx3;
    int sum;
    
    if(nums.empty() or nums.front() > 0 or nums.back() < 0)
        return {};
    
    for(idx1 = 0; idx1 < nums.size()-2; idx1++)
    {
        if(idx1 > 0 and nums[idx1] == nums[idx1-1])
            continue;
        idx2 = idx1 + 1;
        idx3 = nums.size() - 1;
        while(idx2 < idx3)
        {
            sum = nums[idx1] + nums[idx2] + nums[idx3];
            if(sum == 0)
            {
                three_sum[0] = nums[idx1];
                three_sum[1] = nums[idx2];
                three_sum[2] = nums[idx3];

                ans.push_back(three_sum);
                while(idx2 < idx3 and nums[idx2] == nums[idx2+1])
                    idx2++;
                while(idx2 < idx3 and nums[idx3] == nums[idx3-1])
                    idx3--;
                idx2++;
                idx3--;
            }
            else if(sum > 0)
                idx3--;
            else
                idx2++;
        }
    }
    
    return ans;
}

int main()
{
    vector<int> nums = {-1, 0, -1, 1, 2, 4};
    vector<vector<int>> ans;

    ans = threesum(nums);

    return 0;
}