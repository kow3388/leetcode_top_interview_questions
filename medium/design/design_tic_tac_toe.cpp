#include <bits/stdc++.h>

using namespace std;

class TicTacToe
{
    public:
        TicTacToe(int n)
        {
            len = n;
            for(int i = 0; i < n; i++)
            {
                row_check.push_back({-1, 0});
                col_check.push_back({-1, 0});
            }
            dia_check.push_back({-1, 0});
            dia_check.push_back({-1, 0});
        }
        int move(int row, int col, int player)
        {
            if(row_check[row][0] == -1)
            {
                row_check[row][0] = player;
                row_check[row][1]++;
            }
            else if(row_check[row][0] == player and row_check[row][1] == len-1)
                return player;
            else
                if(row_check[row][0] != player)
                    row_check[row][0] = 0;
                else
                    row_check[row][1]++;
            
            if(col_check[col][0] == -1)
            {
                col_check[col][0] = player;
                col_check[col][1]++;
            }
            else if(col_check[col][0] == player and col_check[col][1] == len-1)
                return player;
            else
                if(col_check[col][0] != player)
                    col_check[col][0] = 0;
                else
                    col_check[col][1]++;
            
            if(row == col)
            {
                if(dia_check[0][0] == -1)
                {
                    dia_check[0][0] = player;
                    dia_check[0][1]++;
                }
                else if(dia_check[0][0] == player and dia_check[0][1] == len-1)
                    return player;
                else
                    if(dia_check[0][0] != player)
                        dia_check[0][0] = 0;
                    else
                        dia_check[0][1]++;    
            }

            if(row + col == len-1)
            {
                if(dia_check[1][0] == -1)
                {
                    dia_check[1][0] = player;
                    dia_check[1][1]++;
                }
                else if(dia_check[1][0] == player and dia_check[1][1] == len-1)
                    return player;
                else
                    if(dia_check[1][0] != player)
                        dia_check[1][0] = 0;
                    else
                        dia_check[1][1]++;    
            }
            return 0;
        }
    private:
        int len;
        //{winner, count}
        vector<vector<int>> row_check;
        vector<vector<int>> col_check;
        vector<vector<int>> dia_check;
};