#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int myAtoi(string s)
{
    int i = 0;
    int ans = 0;
    bool neg = false;

    while(s[i] == ' ')
        i++;

    if(s[i] == '-')
    {
        neg = true;
        i++;
    }
    else if(s[i] == '+')
        i++;
    
    while(i < s.length() and isdigit(s[i]))
    {
        if(ans > INT_MAX/10)
            if(neg)
                return INT_MIN;
            else
                return INT_MAX;
        else if(ans == INT_MAX/10)
            if((s[i] - '0') > 7)
                if(neg)
                    return INT_MIN;
                else
                    return INT_MAX;

        ans = ans*10 + (s[i] - '0');
        i++;
    }

    if(neg)
        ans = -ans;


    return ans;
}

int main()
{
    string s = "-4193.52 with words";
    int ans;

    ans = myAtoi(s);

    cout << ans << endl;

    return 0;
}