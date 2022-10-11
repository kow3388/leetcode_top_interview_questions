#include <bits/stdc++.h>

using namespace std;

//brute force
//time: O(sqrt(x))
int mySqrt1(int x)
{
    if(x == 0)
        return 0;
    int ans = 1;
    for(long long i = 1; i < x; i++)
        if(i*i > x)
        {
            ans = i - 1;
            break;
        }
    
    return ans;
}

//binary search
//time: O(logn)
int mySqrt(int x)
{
    long l = 1;
    long r = static_cast<long>(x) + 1;
    while(l < r)
    {
        long m = l + (r - l)/2;
        if(m*m > x)
            r = m;
        else
            l = m + 1;
    }

    return l - 1;
}

int main()
{
    int x = 1;
    int ans = mySqrt(x);

    cout << ans << endl;

    return 0;
}