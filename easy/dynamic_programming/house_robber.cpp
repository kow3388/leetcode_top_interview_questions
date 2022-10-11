#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int rob(vector<int> &nums)
{
    if(nums.size() == 1)
        return nums[0];
    else
    {
        vector<int> max_pro;
        max_pro.push_back(nums[0]);
        if(nums[0] > nums[1])
            max_pro.push_back(nums[0]);
        else
            max_pro.push_back(nums[1]);

        for(int i = 2; i < nums.size(); i++)
            max_pro.push_back(max(max_pro[i-1], max_pro[i-2] + nums[i]));
        
        return max_pro.back();
    }
}

int main()
{
    vector<int> nums = {7,2,3,9,1};
    int ans = rob(nums);

    cout << ans << endl;
    
    return 0;
}