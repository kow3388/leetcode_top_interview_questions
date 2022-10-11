#include <bits/stdc++.h>

using namespace std;

//我寫不出來
string fractionToDecimal(int numerator, int denominator)
{
    stringstream ss,ss2;
 
    long long n = numerator;
    long long d = denominator;
 
    //兩數不同號
    if(n > 0 && d < 0 || n < 0 && d > 0)
    {
      ss << "-";
      n = abs(n);
      d = abs(d);
    }

    //先把整數部分寫入
    ss << (n / d);

    long long r = n % d;

    bool loop = false;
    int count = 0;
    int loop_start;

    if(r)
    {
        n = r;
        ss << ".";
        unordered_map<int, int> rs;
        rs[r] = 0;

        while(r)
        {
            n *= 10;
            r = n % d;
            //ss2是用來塞後面小數點
            ss2 << (n / d);
            n = r;

            //表示出現循環
            if (r && rs.count(r))
            {
                loop = true;
                //開始循環的值
                loop_start = rs[r];
                break;
            }
            //紀錄目前有哪些塞入可能循環
            rs[r] = ++count;
        }

        if(loop)
        {
            auto s2 = ss2.str();
            //先塞入前面不是循環的部分，在塞入循環的部分
            ss << s2.substr(0, loop_start) << "(" << s2.substr(loop_start) << ")";
        }
        else
            ss << ss2.str();
    }

    return ss.str();
}

int main()
{
    int dividend = 4;
    int divisor = 333;
    string ans = fractionToDecimal(dividend, divisor);

    cout << ans << endl;

    return 0;
}