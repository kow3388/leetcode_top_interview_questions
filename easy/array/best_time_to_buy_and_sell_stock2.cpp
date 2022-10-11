#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int pro = 0;

    if(prices.size() == 1)
        return 0;
    else
    {
        for(int i = 0; i < prices.size() - 1; i++)
        {
            if(prices[i+1] > prices[i])
                pro += prices[i+1] - prices[i];
        }

        return pro;
    }
}

int main()
{
    vector<int> prices = {7,6,4,3,1};
    int max_pro;

    max_pro = maxProfit(prices);
    cout << max_pro << endl;

    return 0;
}