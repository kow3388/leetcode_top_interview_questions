#include <bits/stdc++.h>

using namespace std;

int minMeetingRooms(vector<vector<int>> &intervals)
{
    map<int, int> room;
    for(const auto it : intervals)
    {
        room[it[0]]++;
        room[it[1]]--;
    }

    int max_room = 0, curr_room = 0;
    for(const auto m : room)
    {
        curr_room += m.second;
        max_room = max(max_room, curr_room);
    }

    return max_room;
}

int main()
{
    vector<vector<int>> intervals = {{5, 10}, {15, 20}, {0, 30}};
    int ans = minMeetingRooms(intervals);

    cout << ans << endl;

    return 0;
}