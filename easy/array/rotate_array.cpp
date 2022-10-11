#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

void rotate(vector<int> &nums, int k)
{
    k %= nums.size();
    
    if(nums.size() == 1 or k == 0)
        return;
    else
    {
        vector<int> tmp(k);
        for(int i = 0; i < k; i++)
            tmp[i] = nums[nums.size()-k+i];
        
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(i >= k)
                nums[i] = nums[i-k];
            else
                nums[i] = tmp[i];

        }
    }
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    rotate(nums, k);

    return 0;
}