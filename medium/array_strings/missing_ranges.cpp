#include <bits/stdc++.h>

using namespace std;

vector<string> findMissingRanges1(vector<int> &nums, int lower, int upper)
{
    if(nums.size() == 0)
        if(upper == lower)
            return {to_string(lower)};
        else
        {
            string s;
            s.append(to_string(lower));
            s.append("->");
            s.append(to_string(upper));
            return {s};
        }
    else
    {
        int n = nums.size();
        vector<string> ans;
        if(nums[0] - lower == 1)
            ans.push_back(to_string(lower));
        else if(nums[0] - lower > 1)
        {
            string s;
            s.append(to_string(lower));
            s.append("->");
            s.append(to_string(nums[0] - 1));
            ans.push_back(s);
        }

        for(int i = 1; i < n; i++)
        {
            string s;
            if(nums[i] - nums[i-1] == 1)
                continue;
            else if(nums[i] - nums[i-1] == 2)
            {
                s.append(to_string(nums[i] - 1));
                ans.push_back(s);
            }
            else
            {
                s.append(to_string(nums[i-1] + 1));
                s.append("->");
                s.append(to_string(nums[i] - 1));
                ans.push_back(s);  
            }
        }

        if(upper - nums[n-1] == 1)
            ans.push_back(to_string(upper));
        else if(upper - nums[n-1] > 1)
        {
            string s;
            s.append(to_string(nums[n-1] + 1));
            s.append("->");
            s.append(to_string(upper));
            ans.push_back(s);
        }

        return ans;
    }
}


//一樣的想法
//更簡潔的寫法
vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
{
    vector<string> res;
    for (int num : nums)
    {
        if (num > lower) res.push_back(to_string(lower) + (num - 1 > lower ? ("->" + to_string(num - 1)) : ""));
        if (num == upper) return res;
        lower = num + 1;
    }
    if (lower <= upper) res.push_back(to_string(lower) + (upper > lower ? ("->" + to_string(upper)) : ""));
    return res;
}

int main()
{
    vector<int> nums = {0,1,3,50,75};
    int l = 0, u = 99;
    vector<string> ans = findMissingRanges(nums, l, u);

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}