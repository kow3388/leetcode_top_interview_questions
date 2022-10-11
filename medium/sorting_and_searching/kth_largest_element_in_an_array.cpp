#include <bits/stdc++.h>

using namespace std;

//自己寫的方法
//使用hash table
//time: O(element range), space: O(element range)
int findKthLargest1(vector<int> &nums, int k)
{
    unordered_map<int, int> cnt;
    int max_val = INT_MIN;
    int min_val = INT_MAX;
    for(const int num : nums)
    {
        max_val = max(max_val, num);
        min_val = min(min_val, num);
        cnt[num]++;
    }

    int k_tmp = 0;
    for(int i = max_val; i >= min_val; i--)
    {
        k_tmp += cnt[i];
        if(k_tmp >= k)
            return i;
    }

    return 0;
}


//quick selection (和quick sort一樣是partition的概念)
//time: O(n), space: O(1)
int findKthLargest(vector<int> &nums, int k)
{
    nth_element(nums.begin(), nums.begin()+(nums.size() - k), nums.end());

    return nums[nums.size() - k];
}

int main()
{
    vector<int> nums = {4,3,2,3,1,2,5,5,6};
    int k = 4;
    int ans = findKthLargest(nums, k);

    cout << ans << endl;

    return 0;
}