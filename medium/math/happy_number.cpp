#include <bits/stdc++.h>

using namespace std;

bool isHappy(int n)
{
    vector<int> cycle = {4, 16, 37, 58, 89, 145, 42, 20};

    while(n != 1)
    {
        int sum = 0;
        while(n != 0)
        {
            sum += (n%10) * (n%10);
            n /= 10;
        }

        n = sum;

        auto it = find(cycle.begin(), cycle.end(), n);
        if(it != cycle.end())
            return false;
    }

    return true;
}

int main()
{
    int n = 2;
    bool ans = isHappy(n);

    cout << ans << endl;

    return 0;
}