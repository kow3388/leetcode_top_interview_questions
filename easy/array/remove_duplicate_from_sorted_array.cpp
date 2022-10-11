#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if(nums.size() == 1)
        return 1;
    else
    {
        int i = 0;
        int j = 1;
        int cnt = 1;
        while(j < nums.size())
        {
            if(nums[j] > nums[i])
            {
                nums[i+1] = nums[j];
                i++;
                j++;
                cnt++;
            }
            else
                j++;
        }
        return cnt;
    }
}

int main()
{
    int l;
    vector<int> nums = {0,0,0,0,0,0,1};
    l = removeDuplicates(nums);
    cout << l << endl;
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    
    return 0;
}