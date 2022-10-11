#include <bits/stdc++.h>

using namespace std;

int getSum1(int a, int b)
{
    bitset<32> A(a);
    bitset<32> B(b);
    bitset<32> tmp;
    bool carry = false;

    for(int i = 0; i < 32; i++)
    {
        tmp[i] = A[i] ^ B[i] ^ carry;
        carry = (A[i] and B[i]) or (A[i] and carry) or (B[i] and carry);
    }

    int ans = int(tmp.to_ulong());

    return ans;
}

//網路上另一個做法
int getSum(int a, int b)
{
    return b == 0? a : getSum(a^b, (a&b) << 1);
}

int main()
{
    int a = 4;
    int b = 333;
    int ans = getSum(a, b);

    cout << ans << endl;

    return 0;
}