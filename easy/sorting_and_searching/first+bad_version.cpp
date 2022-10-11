#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isBadVersion(int version)
{
    int bad = 170924;

    if(version >= bad)
        return true;
    else
        return false;
}

int _firstBadVersion(int l, int h)
{
    int half = l + (h-l)/2;
    if(!isBadVersion(half))
        return _firstBadVersion(half + 1, h);
    else
    {
        if(!isBadVersion(half - 1))
            return half;
        else
            return _firstBadVersion(l, half);
    }
}

int firstBadVersion(int n)
{
    return _firstBadVersion(1, n);
}

int main()
{
    int n = INT_MAX;
    int ans = firstBadVersion(n);

    cout << ans << endl;

    return 0;
}