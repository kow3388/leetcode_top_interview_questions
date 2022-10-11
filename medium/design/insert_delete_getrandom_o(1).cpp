#include <bits/stdc++.h>

using namespace std;

class RandomizedSet
{
    public:
        RandomizedSet(){}
        
        bool insert(int val)
        {
            if(table.count(val))
                return false;
            else
            {
                table[val] = array.size();
                array.push_back(val);
                return true;
            }
        }
        
        bool remove(int val)
        {
            if(!table.count(val))
                return false;
            else
            {
                int idx = table[val];
                table[array.back()] = idx;
                table.erase(val);
                swap(array[idx], array.back());
                array.pop_back();
                return true;
            }
        }
        
        int getRandom()
        {
            int idx = rand() % array.size();

            return array[idx];
        }
    private:
        unordered_map<int, int> table;
        vector<int> array;
};
