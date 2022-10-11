#include <bits/stdc++.h>

using namespace std;

int hammingDistance(int x, int y)
{
    bitset<32> b_x(x), b_y(y), b;
    b = b_x ^ b_y;

    return b.count();
}

int main()
{
    int x = 1, y = 3;
    int ans = hammingDistance(x, y);

    cout << ans << endl;

    return 0;
}