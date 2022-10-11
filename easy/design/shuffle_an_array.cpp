#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//move是把指向nums的資源直接搶給data用
class Solution
{
    public:
        Solution(vector<int> &nums)
        {
            data = move(nums);
        }
        vector<int> reset()
        {
            return data;
        }
        vector<int> shuffle()
        {
            vector<int> shuffle_data = data;

            for(int i = 0; i < data.size()-1; i++)
            {
                //idx是決定哪格要和i互換
                //範圍為(data.size() - 1) ~ i之間
                int idx = rand()%(data.size() - i) + i;
                swap(shuffle_data[i], shuffle_data[idx]);
            }

            return shuffle_data;
        }
    private:
        vector<int> data;
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution *obj = new Solution(nums);
    vector<int> test = obj->shuffle();

    for(int i = 0; i < test.size(); i++)
        cout << test[i] << " ";
    cout << endl;

    return 0;
}