#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#define empty -1

using namespace std;

//自己沒想到
//先記錄第一航和第一列是否有0
//再用地一行和第一列作紀錄(把其他有0的點map過去)
//where matrix element is 0 then entire row and col set to zeros
void set_zeros(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    bool row_empty = false;
    bool col_empty = false;

    if(row == 0 or col == 0)
        return;
    
    //check first row
    for(int i = 0; i < col; i++)
        if(matrix[0][i] == 0)
        {
            row_empty = true;
            break;
        }
    
    //check first col
    for(int i = 0; i < row; i++)
        if(matrix[i][0] == 0)
        {
            col_empty = true;
            break;
        }

    for(int i = 1; i < row; i++)
        for(int j = 1; j < col; j++)
            if(matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }

    for(int i = 1; i < row; i++)
        for(int j = 1; j < col; j++)
            if(matrix[0][j] == 0 or matrix[i][0] == 0)
                matrix[i][j] = 0;
    
    if(row_empty)
    {
        for(int i = 0; i < col; i++)
            matrix[0][i] = 0;
    }

    if(col_empty)
    {
        for(int i = 0; i < row; i++)
            matrix[i][0] = 0;
    }
}

int main()
{
    vector<vector<int>> matrix1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> matrix2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    vector<vector<int>> matrix3 = {{0, 1, 2, 1}, {0, 4, 5, 2}, {1, 3, 1, 5}};

    set_zeros(matrix3);

    return 0;
}