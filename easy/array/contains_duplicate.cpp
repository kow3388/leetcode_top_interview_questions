#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

bool containDuplicate(vector<int> &nums)
{
    if(nums.size() == 1)
        return false;
    else
    {
        bool ans = false;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 1; i++)
            if(nums[i] == nums[i+1])
            {
                ans = true;
                break;
            }
        return ans;
    }
}

int main()
{
    bool ans;
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    ans = containDuplicate(nums);
    cout << ans << endl;
    
    return 0;
}