#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int> &nums)
{
    if(nums.size() == 1)
        return;
    else
    {
        int n = nums.size();
        vector<int> cnt(3, 0);

        for(int i = 0; i < n; i++)
            cnt[nums[i]]++;

        cnt[2] = cnt[0] + cnt[1];
        cnt[1] = cnt[0];
        cnt[0] = 0;

        for(int i = 0; i < n; i++)
            if(i < cnt[1])
                nums[i] = 0;
            else if(i >= cnt[1] and i < cnt[2])
                nums[i] = 1;
            else
                nums[i] = 2;
    }
}

int main()
{
    vector<int> nums = {2,0,2,1,1,0};

    sortColors(nums);

    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << endl;

    return 0;
}