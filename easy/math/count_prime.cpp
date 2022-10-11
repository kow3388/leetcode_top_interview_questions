#include <bits/stdc++.h>

using namespace std;

//Sieve of Eratosthenes
int countPrimes(int n)
{
    if(n <= 2)
        return 0;
    else
    {
        //數列initial為1
        vector<int> f(n, 1);
        f[0] = f[1] = 0;
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(!f[i])
                continue;
            //把自己外的倍數全部移除
            for(int j = i*i; j < n; j = j+i)
                f[j] = 0;
        }

        return accumulate(f.begin(), f.end(), 0);
    }
}

int main()
{
    int ans = countPrimes(10);

    cout << ans << endl;

    return 0;
}