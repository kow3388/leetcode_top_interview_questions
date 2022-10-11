#include <bits/stdc++.h>

using namespace std;

int bs(vector<int> &nums, int target, int l, int r, bool left, bool right)
{
    if(left)
    {
        while(l < r)
        {
            int m = l + (r - l)/2;
            if(nums[m] > target)
                r = m - 1;
            else
                if(m+1 < nums.size())
                    if(nums[m+1] > nums[m])
                        return m;
                    else
                        l = m + 1;
                else
                    break;
        }
        return l;
    }
    if(right)
    {
        while(l < r)
        {
            int m = l + (r - l)/2;
            if(nums[m] < target)
                l = m + 1;
            else
                if(m-1 >= 0)
                    if(nums[m-1] < nums[m])
                        return m;
                    else
                        r = m - 1;
                else
                    break;
        }
        return l;
    }
}

vector<int> searchRange1(vector<int> &nums, int target)
{
    if(nums.size() == 0)
        return {-1, -1};
    else
    {
        vector<int> ans(2, -1);
        vector<bool> lock(2, false);
        int l = 0, r = nums.size() - 1;

        while(!lock[0] or !lock[1])
        {
            if(l > r)
                break;

            int m = l + (r - l)/2;
            if(nums[l] == target and !lock[0])
            {
                ans[0] = l;
                lock[0] = true;
            }
            if(nums[r] == target and !lock[1])
            {
                ans[1] = r;
                lock[1] = true;
            }
            
            if(nums[m] > target)
                r = m - 1;
            else if(nums[m] < target)
                l = m + 1;
            else
            {
                if(lock[0] and !lock[1])
                {
                    r = bs(nums, target, m, r, true, false);
                    ans[1] = r;
                }
                if(lock[1] and !lock[0])
                {
                    l = bs(nums, target, l, m, false, true);
                    ans[0] = l;
                }
                if(!lock[0] and !lock[1])
                {
                    l = bs(nums, target, l, m, false, true);
                    r = bs(nums, target, m, r, true, false);
                    ans[0] = l;
                    ans[1] = r;
                }
                lock[0] = lock[1] = true;
            }
        }
        return ans;
    }
}

vector<int> searchRange(vector<int> &nums, int target)
{
    if(nums.size() == 0)
        return {-1, -1};
    else
    {
        vector<int> ans(2, -1);
        int l = 0, r = nums.size() - 1;

        while(l <= r)
        {
            int m = l + (r - l)/2;
            if(nums[m] >= target)
                r = m - 1;
            else
                l = m + 1;
        }

        if(nums[l] == target)
            ans[0] = l;
            
        r = nums.size() - 1;
        
        while(l <= r)
        {
            int m = l + (r - l)/2;
            if(nums[m] <= target)
                l = m + 1;
            else
                r = m - 1;
        }

        if(nums[r] == target)
            ans[1] = r;

        return ans;
    }
}

int main()
{
    vector<int> nums = {1};
    int target = 0;
    vector<int> ans = searchRange(nums, target);

    for(int i = 0; i < 2; i++)
        cout << ans[i] << endl;
    
    return 0;
}