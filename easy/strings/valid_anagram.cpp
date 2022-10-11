#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

bool isAnagram(string s, string t)
{
    if(s.length() != t.length())
        return false;
    else
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int i = 0; i < s.length(); i++)
            if(s[i] != t[i])
                return false;
        
        return true;
    }
}

bool isAnagram2(string s, string t)
{
    if(s.length() != t.length())
        return false;
    else
    {
        unordered_map<char, int> count;

        for(int i = 0; i < s.length(); i++)
            count[s[i]]++;
        
        for(int i = 0; i < t.length(); i++)
            if(count[t[i]] == 0)
                return false;
            else
                count[t[i]]--;
        return true;
    }
}

int main()
{
    string s = "anagram";
    string t = "nagaram";
    bool ans;

    ans = isAnagram2(s, t);
    cout << ans << endl;

    return 0;
}