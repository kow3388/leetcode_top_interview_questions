#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    if(matrix.size() == 1)
        return;
    else
    {
        int n = matrix.size();
        for(int i = 0; i < n/2; i++)
            for(int j = i; j < n-1-i; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    rotate(matrix);
    
    return 0;
}