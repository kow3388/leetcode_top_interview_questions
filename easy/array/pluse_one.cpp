#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    if(digits[digits.size()-1] != 9)
    {
        digits[digits.size()-1] += 1;
        return digits;
    }
    else
    {
        for(int i = digits.size()-1; i >= 0; i--)
            if(digits[i] == 9 and i != 0)
                digits[i] = 0;
            else if(digits[i] == 9 and i == 0)
            {
                digits[i] = 0;
                digits.insert(digits.begin(), 1);
            }
            else
            {
                digits[i] += 1;
                break;
            }
        
        return digits;
    }
}

int main()
{
    vector<int> digits = {9, 8, 9};
    vector<int> ans;

    ans = plusOne(digits);

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i];
    cout << endl;

    return 0;
}