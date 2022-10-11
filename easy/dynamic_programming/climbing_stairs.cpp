#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n)
{
    vector<int> record = {1, 2};

    if(n == 1 or n == 2)
        return record[n-1];
    else
    {
        int ans;

        for(int i = 2; i < n; i++)
        {
            ans = record[i-1] + record[i-2];
            record.push_back(ans);
        }

        return record.back();
    }
}

int main()
{
    int n = 3;
    int ans = climbStairs(n);

    cout << ans << endl;
    
    return 0;
}