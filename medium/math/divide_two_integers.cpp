#include <bits/stdc++.h>

using namespace std;

//我只想得到brute force
//轉換成2進制的除法
//https://medium.com/@ChYuan/leetcode-29-divide-two-integers-%E5%BF%83%E5%BE%97-medium-91e5fccb29fa
int divide(int dividend, int divisor)
{
    if(divisor == INT_MIN)
        return dividend == INT_MIN? 1 : 0;
    if(dividend == INT_MIN)
    {
        if(divisor == -1)
            return INT_MAX;
        return divisor > 0 ? divide(dividend + divisor, divisor) - 1 : divide(dividend - divisor, divisor) + 1;
    }

    int a = abs(dividend);
    int b = abs(divisor);
    int ans = 0;

    for(int i = 31; i >= 0; i--)
        if(a >> i >= b)
        {
            ans += 1 << i;
            a -= b << i;
        }

    return (dividend > 0) == (divisor > 0) ? ans : -ans;
}

int main()
{
    int dividend = 10;
    int divisor = 3;
    int ans = divide(dividend, divisor);

    cout << ans << endl;

    return 0;
}