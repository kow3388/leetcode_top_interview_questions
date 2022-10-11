#include <bits/stdc++.h>

using namespace std;

bool isValid(string s)
{
    if(s.length() == 1)
        return false;
    else
    {
        vector<char> tmp;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' or s[i] == '[' or s[i] == '{')
                tmp.push_back(s[i]);
            else
                if(tmp.empty())
                    return false;
                else
                {
                if(s[i] == ')')
                    if(tmp.back() != '(')
                        return false;
                    else
                        tmp.pop_back();
                else if(s[i] == ']')
                    if(tmp.back() != '[')
                        return false;
                    else
                        tmp.pop_back();
                else
                    if(tmp.back() != '{')
                        return false;
                    else
                        tmp.pop_back();
                }
        }

        if(!tmp.empty())
            return false;
        
        return true;
    }
}

int main()
{
    string s = "}(";
    bool ans = isValid(s);

    cout << ans << endl;

    return 0;
}