#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    int l1 = nums1.size();
    int l2 = nums2.size();
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0;
    int j = 0;

    while(i < l1 and j < l2)
    {
        if(nums1[i] == nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i] > nums2[j])
            j++;
        else
            i++;
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> ans;

    ans = intersect(nums1, nums2);

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    
    return 0;
}