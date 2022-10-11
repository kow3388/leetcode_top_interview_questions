#include <bits/stdc++.h>

using namespace std;

//自己沒想出來

string longestPalidrome(string s)
{
    const int n = s.length();
    //檢查是不是回文，並回傳回文的長度
    auto getLen = [&](int l, int r)
    {
        while(l >= 0 and r < n and s[l] == s[r])
        {
            l--;
            r++;
        }

        return r - l - 1;
    };

    int max_len = 0;
    int start = 0;

    //所有可能看過一遍
    for(int i = 0; i < n; i++)
    {
        int curr = max(getLen(i, i), getLen(i, i + 1));  //回文是奇數字還是偶數字

        if(curr > max_len)
        {
            max_len = curr;
            start = i - (max_len - 1)/2;
        }
    }

    return s.substr(start, max_len);
}

int main()
{
    string s = "babad";
    string ans = longestPalidrome(s);

    cout << ans << endl;

    return 0;
}