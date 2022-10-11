#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int strStr(string haystack, string needle)
{
    int idx;
    bool flag;
    
    for(int i = 0; i < haystack.length(); i++)
    {
        idx = i;
        flag = false;
        for(int j = 0; j < needle.length(); j++)
        {
            if(needle[j] == haystack[i+j])
                flag = true;
            else
            {
                idx = -1;
                flag = false;
                break;
            }
        }

        if(flag)
            break;
    }

    return idx;
}

//有官方find函數套件可以用
int strStr_key(string haystack, string needle)
{
    ssize_t pos = haystack.find(needle);
    //size_t 依據系統來配置大小, ssize_t表示sign的size_t

    return pos;
}

int main()
{
    string haystack = "mississippi";
    string needle = "issipt";

    int ans;

    ans = strStr_key(haystack, needle);
    cout << ans << endl;
    
    return 0;
}