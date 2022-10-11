#include<bits/stdc++.h>

using namespace std;

int hammingWeight(uint32_t n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
    {
        int cnt = 0;

        while(n > 1)
        {
            if(n%2 == 1)
                cnt++;
            n /= 2;
        }

        if(n == 1)
            cnt++;

        return cnt;
    }
}

//用套件作法
int hammingWeight2(uint32_t n)
{
    bitset<32> b(n);

    return b.count();
}

int main()
{
    uint32_t n = 128;
    int ans = hammingWeight(n);

    cout << ans << endl;

    return 0;
}