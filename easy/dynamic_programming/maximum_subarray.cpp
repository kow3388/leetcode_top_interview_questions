#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//dynamic programming
int maxSubArray(vector<int> &nums)
{
    int tmp;
    if(nums[0] > 0)
        tmp = nums[0];
    else
        tmp = 0;

    int ans = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        if(tmp + nums[i] > 0)
        {
            tmp += nums[i];
            if(tmp > ans)
                ans = tmp;
        }
        else
        {
            tmp = 0;
            if(nums[i] > ans)
                ans = nums[i];
        }
    }

    return ans;
}

//divide and conquer
int CrossMax(vector<int> &nums, int start, int mid, int end)
{
    int left_max = nums[mid];
    int right_max = nums[mid+1];
    int left_sum = 0, right_sum = 0;

    for(int i = mid; i >= start; i--)
    {
        left_sum += nums[i];
        left_max = max(left_sum, left_max);
    }

    for(int i = mid + 1; i <= end; i++)
    {
        right_sum += nums[i];
        right_max = max(right_sum, right_max);
    }

    return max(max(left_max, right_max), left_max + right_max);
}

int GetMax(vector<int> &nums, int start, int end)
{
    if(start == end)
        return nums[start];
    else
    {
        int mid = start + (end - start)/2;
        int left_max = GetMax(nums, start, mid);
        int right_max = GetMax(nums, mid+1, end);

        int cross_max = CrossMax(nums, start, mid, end);

        return max(max(left_max, right_max), cross_max);
    }
}

int maxSubArray2(vector<int> &nums)
{
    return GetMax(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {5,4,-1,7,8};
    int ans = maxSubArray2(nums);

    cout << ans << endl;

    return 0;
}