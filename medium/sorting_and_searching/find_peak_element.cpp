#include <bits/stdc++.h>

using namespace std;

//自己寫的
//time: O(n), space: O(1)
int findPeakElement1(vector<int> &nums)
{
    if(nums.size() == 1)
        return 0;
    else if(nums.size() == 2)
        if(nums[0] > nums[1])
            return 0;
        else
            return 1;
    else
    {
        int n = nums.size();
        if(nums[0] > nums[1])
            return 0;
        if(nums[n-1] > nums[n-2])
            return n-1;
        
        int i = 0, j = 1, k = 2;
        while(k < n)
        {
            if(nums[j] > nums[i] and nums[j] > nums[k])
                return j;
            i++;
            j++;
            k++;
        }
    }
}

//binary search
//time: O(logn), space: O(1)
int findPeakElement(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    while(l < r)
    {
        int m = l + (r - l)/2;
        //先找到中間值比右邊大的地方
        //如果不符合，則表示找到一個中間值比左邊大的地方
        if(nums[m] > nums[m+1])
            r = m;
        else
            l = m + 1;
    }

    return l;
}

int main()
{
    vector<int> nums = {1,1,1,3,1,6,7,4};
    int ans = findPeakElement(nums);

    cout << ans << endl;
    
    return 0;
}