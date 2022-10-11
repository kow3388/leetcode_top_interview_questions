#include <bits/stdc++.h>

using namespace std;

//O(n^2)
int lengthOfLongestSubstring1(string s)
{
    if(s.length() == 0)
        return 0;
    else if(s.length() == 1)
        return 1;
    else
    {
        unordered_map<char, int> map;
        int cnt = 1;
        for(int i = 0; i < s.length() - 1; i++)
        {
            int cnt_tmp = 1;
            map[s[i]] = i;
            for(int j = i+1; j < s.length(); j++)
            {
                if(!map.count(s[j]))
                {
                    cnt_tmp++;
                    map[s[j]] = j;
                    cnt = max(cnt_tmp, cnt);
                }
                else
                {
                    map.clear();
                    break;
                }
            }
        }
        return cnt;
    }
}

//O(n)
//128是因為總共有128個char
//i是slinding windows的起點
//i的算法是，如果前面沒出現重複的字，則維持目前的i
//如果有出現過，則在上次出現的位置+1當作起點
//j是目前的位置，idx是紀錄最後一次出現的位置
//j-i+1是目前長度
int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    int ans = 0;
    vector<int> idx(128, -1);
    for(int i = 0, j =0; j < n; j++)
    {
        i = max(i, idx[s[j]] + 1);
        ans = max(ans, j - i + 1);
        idx[s[j]] = j;
    }
    return ans;
}

int main()
{
    string s = "bbbbb";
    int ans = lengthOfLongestSubstring(s);

    cout << ans << endl;

    return 0;
}