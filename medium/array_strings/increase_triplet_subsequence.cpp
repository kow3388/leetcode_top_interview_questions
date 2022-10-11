#include<bits/stdc++.h>

using namespace std;

//自己沒想出來
//採用greedy algo
//找到目前最小，如果遇到比自己小的改變最小
bool increasingTriplet(vector<int> &nums)
{
    int n = nums.size();

    if(n < 3)
        return false;
    else
    {
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > min1 and nums[i] > min2)
                return true;
            else if(nums[i] < min1)
                min1 = nums[i];
            else if(nums[i] > min1 and nums[i] < min2)
                min2 = nums[i];
        }

        return false;
    }
}

int main()
{
    vector<int> nums = {2,1,5,0,4,6};
    bool ans = increasingTriplet(nums);

    cout << ans << endl;
    
    return 0;
}