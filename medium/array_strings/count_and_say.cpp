#include<bits/stdc++.h>

using namespace std;

//自己寫的垃圾方法
string _countAndSay1(string s)
{
    int n = s.length();
    vector<vector<int>> num_cnt;
    int num = s[0] - '0';
    int cnt = 1;
    if(n == 1)
        return "11";
    else
    {
        for(int i = 1; i < n; i++)
        {
            int tmp = s[i] - '0';
            if(tmp == num)
            {
                cnt++;
            }
            else
            {
                vector<int> str_tmp;
                str_tmp.push_back(cnt);
                str_tmp.push_back(num);
                num_cnt.push_back(str_tmp);

                cnt = 1;
                num = tmp;
            }
        }

        vector<int> str_tmp;
        str_tmp.push_back(cnt);
        str_tmp.push_back(num);
        num_cnt.push_back(str_tmp);

        string s_return;
        for(int i = 0; i < num_cnt.size(); i++)
            for(int j = 0; j < 2; j++)
                s_return.push_back(char(num_cnt[i][j] + '0'));
        
        return s_return;
    }
}

//別人的方法跟我一樣，只是寫法寫得很簡單
string _countAndSay(string str)
{
    string ans;
    int s = 0, l = str.length();
    for(int i = 1; i <= l; i++)
    {
        if(i == l or str[s] != str[i])
        {
            int cnt = i - s;
            ans += '0' + cnt;
            ans += str[s];
            s = i;
        }
    }

    return ans;
}

string countAndSay(int n)
{
    string s;

    for(int i = 1; i <= n; i++)
        if(i == 1)
            s = "1";
        else
            s = _countAndSay(s);

    return s;
}

int main()
{
    int n = 4;
    string ans = countAndSay(n);

    cout << ans << endl;
    
    return 0;
}