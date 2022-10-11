#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

void reverseString(vector<char> &s)
{
    if(s.size() == 1)
        return;
    else
    {
        int i = 0;
        int j = s.size() - 1;

        while(i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
}

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    reverseString(s);

    for(int i = 0; i < s.size(); i++)
        cout << s[i];
    cout << endl;
    
    return 0;
}