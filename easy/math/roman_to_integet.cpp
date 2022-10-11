#include <bits/stdc++.h>

using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> map = {{'I', 1},
                                    {'V', 5},
                                    {'X', 10},
                                    {'L', 50},
                                    {'C', 100},
                                    {'D', 500},
                                    {'M', 1000}};
    if(s.length() == 1)
        return map[s[0]];
    else
    {
        int ans = map[s[0]];
        for(int i = 1; i < s.length(); i++)
        {
            ans += map[s[i]];
            if(map[s[i]] > map[s[i-1]])
                ans -= 2*map[s[i-1]];
        }

        return ans;
    }
}

int main()
{
    string s = "MCMXCIV";
    int ans = romanToInt(s);

    cout << ans << endl;

    return 0;
}