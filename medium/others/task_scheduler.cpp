#include <bits/stdc++.h>

using namespace std;

//想不到
int leastInterval(vector<char> &tasks, int n)
{
    vector<int> cnt(26, 0);
    for(const auto task : tasks)
        cnt[task - 'A']++;
    
    const int max_cnt = *max_element(cnt.begin(), cnt.end());
    //可以分成max_cnt個組，最後一個組完成後會結束，因此沒必要在idle
    //所以是max_cnt-1
    //每一組會有n+1個task(包含idle)，因為同task中間要隔n，所以每一組會是n+1
    size_t ans = (max_cnt-1)*(n+1);
    //計算有多少個最大元素個數
    function<bool(int)> myfunc = [max_cnt](int c)
    {
        return c == max_cnt;
    };

    //最後一組沒有idel但還是會有task，因此要把剩餘的task塞入
    ans += count_if(cnt.begin(), cnt.end(), myfunc);

    //避免n=0的情況
    return max(tasks.size(), ans);
}

int main()
{
    vector<char> tasks = {
        'A','A','A','A','A','A','B','C','D','E','F','G'
    };
    int n = 2;
    int ans = leastInterval(tasks, n);

    cout << ans << endl;

    return 0;
}