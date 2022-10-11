#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string s)
{
    if(s.length() == 1)
        return true;
    else
    {
        int i = 0;
        int j = s.length() - 1;

        while(i < j)
        {
            while(!isalnum(s[i]) and i < j)
                i++;
            while(!isalnum(s[j]) and i < j)
                j--;
            
            if(toupper(s[i]) != toupper(s[j]))
                return false;
            
            i++;
            j--;
        }
        return true;
    }
}

int main()
{
    string s = "0P";
    bool ans;

    ans = isPalindrome(s);
    cout << ans << endl;

    //A:65, Z:90, a:97, z:122, 0:48, 9:57

    return 0;
}