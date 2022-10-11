#include <bits/stdc++.h>

using namespace std;


int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++)
        if(i != nums[i])
            return i;

    return nums.size();
}

//用sum或xor解，只需O(n)
int missingNumber_sum(vector<int> &nums)
{
    int value = (nums.size() + 1)*nums.size()/2;
    int nums_sum = accumulate(nums.begin(), nums.end(), 0);

    return value - nums_sum;
}

//xor原理是因為自己跟自己xor一定是0，所以我們把i和nums做xor，必定會剩下一個沒有跟自己xor的i
//之所以從1開始到nums.size()還要檢查最大值
int missingNumber_xor(vector<int> &nums)
{
    int x = 0;
    for(int i = 1; i <= nums.size(); i++)
        x = x ^ i ^ nums[i-1];
    
    return x;
}

int main()
{
    vector<int> nums = {3,0,1};
    int ans = missingNumber_xor(nums);

    cout << ans << endl;

    return 0;
}