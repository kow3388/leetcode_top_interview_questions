#include <bits/stdc++.h>

using namespace std;

//自己沒想到
//用priority queue解 (c++的priority是用max heap)
//time: O(n) + O(nlogn), space O(n)
vector<int> topKFrequent1(vector<int> &nums, int k)
{
    //計算每種element的個數
    unordered_map<int, int> cnt;
    for(const int num : nums)
        cnt[num]++;
    
    priority_queue<pair<int, int>> q;
    for(const auto &pair : cnt)
    {
        //pair.first => vector裡面的element數值
        //pair.second => element數值的個數
        //因為priority queue是用max heap，所以把所有個數取負號
        //數量最多的會變負最大，會維持在下面
        //priority queue是以第一個值最heap
        q.emplace(-pair.second, pair.first);
        if(q.size() > k)
            q.pop();
    }

    vector<int> ans;
    for(int i = 0; i < k; i++)
    {
        ans.push_back(q.top().second);
        q.pop();
    }
    return ans;
}

//自己沒想到
//第二種方法是用bucket sort
//time: O(n), space: O(n)
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> cnt;
    int max_freq = 1;

    //先找出個數最多的值
    for(const int num : nums)
        max_freq = max(max_freq, ++cnt[num]);
    
    map<int, vector<int>> buckets;
    //bucket存放個數=n的element
    for(const auto &kv : cnt)
        buckets[kv.second].push_back(kv.first);
    
    vector<int> ans;
    //從個數最大的開始往下找
    for(int i = max_freq; i >= 1; i--)
    {
        auto it = buckets.find(i);
        //如果這個if成立，表示沒有element是這個個數
        if(it == buckets.end())
            continue;
        ans.insert(ans.end(), it->second.begin(), it->second.end());
        if(ans.size() == k)
            return ans;
    }
}

int main()
{
    vector<int> nums = {1,1,1,2,2,3,3,2,1,2};
    int k = 2;
    vector<int> ans = topKFrequent(nums, k);

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    
    return 0;
}