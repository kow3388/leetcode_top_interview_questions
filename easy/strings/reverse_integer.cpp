#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int reverse(int x)
{
    int rev= 0;
    int min_check = INT_MIN/10;
    int max_check = INT_MAX/10;
    while( x != 0)
    {
        if(x/10 == 0)
        {
            if(rev > max_check or rev < min_check)
                return 0;
            else if(rev == max_check or rev == min_check)
                if(x%10 > 7 or x%10 < -8)
                    return 0;
        }
        rev = rev*10 + x % 10;
        x /= 10;
    }

    return rev;
}

int main()
{
    int x = -2147483412;
    int ans;

    ans = reverse(x);

    cout << ans << endl;

    return 0;
}