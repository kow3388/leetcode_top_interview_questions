#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int singleNumber(vector<int> &nums)
{
    if(nums.size() == 1)
        return nums[0];
    else
    {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1])
                continue;
            else
                if(i == 0)
                    return nums[i];
                else if((i+1) == nums.size()-1)
                    return nums[i+1];
                else
                {
                    if(nums[i+1] == nums[i+2])
                        i += 1;
                    else
                        return nums[i+1];
                }

        }
    }
}


//官方給的是O(n)
int best_solution(vector<int> nums)
{
    int ans = 0;
    for(int i = 0; i < nums.size(); i++)
        ans ^= nums[i];
    
    return ans;
}

int main()
{
    int ans;
    vector<int> nums = {4,1,2,1,2};
    ans = singleNumber(nums);
    cout << ans << endl;
    
    return 0;
}