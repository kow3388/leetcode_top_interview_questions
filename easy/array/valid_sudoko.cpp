#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

/*把3種規則分別記錄在tmp當中，如果符合規則的情況，map tmp會長成這樣
{
    [1, 2, 3, 4, 5, 6, 7, 8, 9],
    [1, 2, 3, 4, 5, 6, 7, 8, 9],
    [1, 2, 3, 4, 5, 6, 7, 8, 9],
    [1, 2, 3, 4, 5, 6, 7, 8, 9],
    [1, 2, 3, 4, 5, 6, 7, 8, 9],
    [1, 2, 3, 4, 5, 6, 7, 8, 9],
    [1, 2, 3, 4, 5, 6, 7, 8, 9],
    [1, 2, 3, 4, 5, 6, 7, 8, 9],
    [1, 2, 3, 4, 5, 6, 7, 8, 9]
}*/

bool isValidSudoku(vector<vector<char>> &board)
{
    int tmp1[9][9] = {0};
    int tmp2[9][9] = {0};
    int tmp3[9][9] = {0};

    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] != '.')
            {   
                int num = (int)board[i][j] - (int)'1';
                int k = i/3*3 + j/3;

                if(tmp1[i][num] or tmp2[j][num] or tmp3[k][num])
                    return false;
                
                tmp1[i][num] = tmp2[j][num] = tmp3[k][num] = 1;
            }
        }

    return true;
}

int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    bool ans;

    ans = isValidSudoku(board);
    cout << ans << endl;

    return 0;
}