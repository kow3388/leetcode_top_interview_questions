#include <bits/stdc++.h>

using namespace std;

//自己寫的，用hash table
//time: O(n), space: O(n)
int majorityElement1(vector<int> &nums)
{
    if(nums.size() == 1)
        return nums[0];
    else
    {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i++)
            if(++cnt[nums[i]] > n/2)
                return nums[i];

        return -1;
    }
}

//網路上其他寫法
//partial sorting
//因為如果有元素大於一版的數量那麼中間的位置一定是那個元素
//time: O(n), space: O(1)
int majorityElement(vector<int> &nums)
{
    nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());

    return nums[nums.size()/2];
}

int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    int ans = majorityElement(nums);

    cout << ans << endl;

    return 0;
}