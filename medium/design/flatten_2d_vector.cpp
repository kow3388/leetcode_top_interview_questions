#include <bits/stdc++.h>

using namespace std;

class Vector2D
{
    public:
        Vector2D(vector<vector<int>> &vec)
        {
            for(const auto &v : vec)
                flatten.insert(flatten.end(), v.begin(), v.end());
            idx = -1;
        }
        int next()
        {
            idx++;
            return flatten[idx];
        }
        bool hasNext()
        {
            if(idx+1 >= flatten.size())
                return false;
            else
                return true;
        }
    private:
        vector<int> flatten;
        int idx;
};