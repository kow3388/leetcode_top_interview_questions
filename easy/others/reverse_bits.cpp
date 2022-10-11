#include <bits/stdc++.h>

using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t ans;

    //n&1是判斷下一個要塞的是1還是0
    for(int i = 0; i < 32; i++)
    {
        ans = (ans << 1) | (n & 1);
        n >>= 1;
    }

    return ans;
}

int main()
{
    uint32_t n = 1;
    uint32_t ans = reverseBits(n);

    cout << ans << endl;

    return 0;
}