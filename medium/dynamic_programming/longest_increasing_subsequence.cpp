#include <bits/stdc++.h>

using namespace std;

//我想不到
//time: O(n^2)
int lengthOfLIS1(vector<int> &nums)
{
    if(nums.empty())
        return 0;
    else if(nums.size() == 1)
        return 1;
    else
    {
        int n = nums.size();
        auto f = vector<int>(n, 1);
        for(int i = 1; i < n; i++)
            for(int j = 0; j < i; j++)
                //想以nums[i]結尾，所以只要考慮前面比nums[i]還小的值
                if(nums[i] > nums[j])
                    //判斷加不加會不會比較長
                    f[i] = max(f[i], f[j] + 1);

        return *max_element(f.begin(), f.end());
    }
}

//第二個方法是dp + binary search
//time: O(nlogn)
int lengthOfLIS(vector<int> &nums)
{
    const int n = nums.size();
    if(n == 0)
        return 0;
    else
    {
        vector<int> dp;
        for(int i = 0; i < n; i++)
        {
            //lower_bound: 把nums[i]當最小值，找出dp中>=nums[i]的位置
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            //如果在最後面表示可以把此值送入dp
            if(it == dp.end())
                dp.push_back(nums[i]);
            //如果不是在最後，則把其dp對應位置的數值改成nums[i]
            //用意是把最後一個數更新為最小的值
            //ex: [1,2,3] 和 [1,2,8]比較，[1,2,3]比較好
            //因為3後面比8好加數字
            else
                *it = nums[i];
        }
        
        return dp.size();
    }
}

int main()
{
    vector<int> nums = {10,9,4,5,3,7,101,18};
    int ans = lengthOfLIS(nums);

    cout << ans << endl;

    return 0;
}