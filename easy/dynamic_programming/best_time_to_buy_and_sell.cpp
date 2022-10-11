#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//DP都是用空間換時間
//min_price紀錄目前為止最低價
//max_profit跟前一個時間點比較，是現在獲益最高還是前一個時間點獲益較高
int maxProfit(vector<int> &prices)
{
    if(prices.size() == 1)
        return 0;
    else
    {
        vector<int> min_price(prices.size());
        vector<int> max_profit(prices.size());

        min_price[0] = prices[0];
        max_profit[0] = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            min_price[i] = min(prices[i], min_price[i-1]);
            max_profit[i] = max(prices[i] - min_price[i-1], max_profit[i-1]);
        }

        return max_profit.back();
    }
}

//用maximum subarray去解
int maxProfit2(vector<int> &prices)
{
    if(prices.size() == 1)
        return 0;
    else
    {
        vector<int> day_profit;
        int profit = 0;
        int max_profit = profit;

        for(int i = 0; i < prices.size() - 1; i++)
            day_profit.push_back(prices[i+1] - prices[i]);
        
        for(int i = 0; i < day_profit.size(); i++)
        {
            if(profit + day_profit[i] > 0)
            {
                profit += day_profit[i];

                if(profit > max_profit)
                    max_profit = profit;
            }
            else
                profit = 0;
        }

        return max_profit;
    }
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4,8,2,3};
    int ans = maxProfit2(prices);

    cout << ans << endl;

    return 0;
}