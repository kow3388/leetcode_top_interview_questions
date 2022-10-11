#include <bits/stdc++.h>

using namespace std;

//自己寫不出來
//用兩個pointer
//分別是row = 0和col = last col
//開始比較，若現值比target小，row++
//若現值比target大，col--
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int row = 0, col = n - 1;
    while(row < m and col >= 0)
        if(matrix[row][col] == target)
            return true;
        else if(matrix[row][col] > target)
            col--;
        else
            row++;

    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1,3,5,7,9},
        {2,4,6,8,10},
        {11,13,15,17,19},
        {12,14,16,18,20},
        {21,22,23,24,25}
    };
    int target = 13;
    bool ans = searchMatrix(matrix, target);

    cout << ans << endl;

    return 0;
}