#include <bits/stdc++.h>

using namespace std;

//這樣會time out
double myPow1(double x, int n)
{
    if(n >= 0)
    {
        double ans = 1.0;
        for(int i = 0; i < n; i++)
            ans *= x;
        
        return ans;
    }
    else
    {
        n = -n;
        double ans = 1.0;
        for(int i = 0; i < n; i++)
            ans *= x;
        
        return 1.0/ans;
    }
}

//網路上的作法
double myPow_(double x, int n)
{
    if(n == 0)
        return 1;
    else
    //把n用bit表示，例如: 6 => 110
    //每個bit表示x^b , b => 第幾個bit
        return myPow_(x*x, n/2) * (n%2 ? x : 1);
}

double myPow(double x, int n)
{
    return n >= 0? myPow_(x, n) : 1.0/myPow_(x, n);
}

//這樣leetcode也會過
double myPow2(double x, int n)
{
    return pow(x, n);
}

int main()
{
    double x = 2.0;
    int n = 1;
    double ans = myPow(x, n);

    cout << ans << endl;

    return 0;
}