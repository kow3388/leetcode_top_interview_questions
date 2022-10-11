#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    if(nums.size() == 1)
        return;
    else
    {
        int i = 0;
        int j = 0;

        while(i < nums.size() and j < nums.size())
            if(nums[i] != 0)
            {
                i++;
                j = i + 1;
            }
            else
            {
                if(nums[j] == 0)
                    j++;
                else
                {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    i++;
                    j++;
                }
            }
    }
}

int main()
{
    vector<int> nums = {0,1,0,3,12};

    moveZeroes(nums);
    
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}