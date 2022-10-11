#include <bits/stdc++.h>

using namespace std;

//這個是我的寫法，去計算有多少個5
int trailingZeroes1(int n)
{
    if(n < 5)
        return 0;
    else
    {
        int cnt = 0;
        int idx = 5;

        while(idx <= n)
        {
            int tmp_cnt = 1;
            int tmp = pow(5, tmp_cnt);
            while(!(idx % tmp))
            {
                    tmp_cnt++;
                    tmp = pow(5, tmp_cnt);
            }
            tmp_cnt--;
            cnt += tmp_cnt;
            idx += 5;
        }

        return cnt;
    }
}

//網路上其他人的寫法，一樣是去計算有多少個5
//只不過是用recursive的方式
//而且我是一個一個5去算，他是用更有效率的算法
// n/5表示有多少個數字可以被5整除，在送到下一層時
// 這n/5個數字又有多少可以在被5整除
int trailingZeroes(int n)
{
    return n < 5 ? 0 : n /5 + trailingZeroes(n / 5);
}

int main()
{
    int n = 30;
    int ans = trailingZeroes(n);

    cout << ans << endl;

    return 0;
}