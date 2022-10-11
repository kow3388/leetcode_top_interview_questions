#include <bits/stdc++.h>

using namespace std;

int BS(vector<int> &nums, int target, int l, int r)
{
    while(l < r)
    {
        int m = l + (r - l)/2;
        if(nums[m] == target)
            return m;
        else if(nums[m] > target)
            r = m;
        else
            l = m + 1;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    if(nums.size() == 1)
        if(nums[0] == target)
            return 0;
        else
            return -1;
    else
    {
        int l = 0;
        int r = nums.size() - 1;
        int m = l + (r - l)/2;

        //找交界點，順便看能不能撈到target
        while(l < r)
        {
            m = l + (r - l)/2;
            if(nums[l] == target)
                return l;
            if(nums[r] == target)
                return r;
            if(nums[m] == target)
                return m;

            if(nums[m] > nums[m+1])
            {
                m++;
                break;
            }
            else if(nums[m] < nums[m-1])
                break;
            if(nums[m] > nums[l])
                l = m + 1;
            if(nums[m] < nums[r])
                r = m - 1;
        }

        if(target >= nums[m] and target <= nums[nums.size() - 1])
            return BS(nums, target, m, nums.size() - 1);
        else if(target <= nums[m-1] and target >= nums[0])
            return BS(nums, target, 0, m);
        else
            return -1;
    }
}

int main()
{
    vector<int> nums = {1,3};
    int target = 0;
    int ans = search(nums, target);

    cout << ans << endl;

    return 0;
}