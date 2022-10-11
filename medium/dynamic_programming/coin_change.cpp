#include <bits/stdc++.h>

using namespace std;

//自己想不出來
//using knapsack
int coinChange1(vector<int> &coins, int amount)
{
    if(amount == 0)
        return 0;
    else if(coins.size() == 1)
        if(amount%coins[0] == 0)
            return amount/coins[0];
        else
            return -1;
    else
    {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        //coin表示我目前能使用到哪種coin
        for(int coin : coins)
        {
            for(int i = coin; i <= amount; i++)
                if(dp[i - coin] != INT_MAX)
                    //去比較dp[i-coin]是因為i是我要到達的值-coin表示我可以把其中的一部分變成現在最大面額
                    //的coin，若dp[i-coin]不是INT_MAX, i-coin是有辦法被表示的
                    dp[i] = min(dp[i], dp[i-coin]+1);
        }
        //判斷484 INT_MAX => 有沒有辦法被兌換
        return dp[amount] == INT_MAX? -1 : dp[amount];
    }
}

void coinchange(const vector<int> &coins, int s, int amount, int count, int &ans)
{
    if(amount == 0)
    {
        ans = min(ans, count);
        return;
    }
    if(s == coins.size())
        return;
    
    const int coin = coins[s];
    //從最大coin值開始拿如果，k initial最多可以拿多少個這個值的coin
    //如果amount = 0表示可以兌換完，如果不行則s = coins.size(所有硬幣都看過還是沒辦法對換完)
    //ans挑小的為最佳解
    for(int k = amount/coin; k >= 0 and count + k < ans; k--)
        coinchange(coins, s+1, amount - k*coin, count + k, ans);
}

//第二個解法是用DFS
int coinChange(vector<int> &coins, int amount)
{
    sort(coins.rbegin(), coins.rend());
    int ans = INT_MAX;
    coinchange(coins, 0, amount, 0, ans);

    return ans == INT_MAX? -1 : ans;
}

int main()
{
    vector<int> coin = {1,2,5};
    int amount = 11;
    int ans = coinChange(coin, amount);

    cout << ans << endl;

    return 0;
}