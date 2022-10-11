#include <bits/stdc++.h>

using namespace std;

int titleToNumber(string columnTitle)
{
    int n = columnTitle.length();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans *= 26;
        ans += (int(columnTitle[i]) - 'A' + 1);
    }

    return ans;
}

int main()
{
    string s = "AB";
    int ans = titleToNumber(s);

    cout << ans << endl;

    return 0;
}