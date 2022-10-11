#include <bits/stdc++.h>

using namespace std;

//沒看懂題目，也沒想出來
//題意為我所在的index，裡面的值v表示我可以移動0~v的距離
//用greedy
//紀錄目前的位置最遠可到哪以及現在的位置最遠可到哪
//如果現在的位置超越目前可到的最遠位置，表示無法到達，break
bool canJump(vector<int> &nums)
{
    if(nums.size() == 1)
        return true;
    else
    {
        const int n = nums.size();
        int far = nums[0];
        for(int i = 0; i < n; i++)
        {
            if(i > far)
                break;
            far = max(far, i + nums[i]);
        }

        //判斷我們可到的最遠距離是否為最後一個位置
        return far >= n-1;
    }
}

int main()
{
    vector<int> nums = {2,3,5,1,4};
    bool ans = canJump(nums);

    cout << ans << endl;

    return 0;
}