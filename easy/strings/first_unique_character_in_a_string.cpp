#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int firstUniqChar(string s)
{
    if(s.length() == 1)
        return 0;
    else
    {
        unordered_map<char,  int> idx;
        for(int i = 0; i < s.length(); i++)
            idx[s[i]]++;
        for(int i = 0; i < s.length(); i++)
            if(idx[s[i]] == 1)
                return i;
        return -1;
    }
}

int main()
{
    string s = "loveleetcode";
    int ans;

    ans = firstUniqChar(s);
    cout << ans << endl;

    return 0;
}