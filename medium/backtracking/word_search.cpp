#include <bits/stdc++.h>

using namespace std;

bool DFS(vector<vector<char>> &board, string word,
         int idx, int i, int j, int row, int col, int len)
{
    if(i < 0 or j < 0 or i >= row or j >= col or board[i][j] != word[idx])
        return false;
    else if(idx == len-1)
        return true;
    else
    {
        char tmp = board[i][j];
        board[i][j] = '0';
        bool ans = DFS(board, word, idx+1, i, j+1, row, col, len)
                || DFS(board, word, idx+1, i+1, j, row, col, len)
                || DFS(board, word, idx+1, i, j-1, row, col, len)
                || DFS(board, word, idx+1, i-1, j, row, col, len);
        board[i][j] = tmp;

        return ans;
    }
}

bool exist(vector<vector<char>> &board, string word)
{
    int len = word.length();
    int row = board.size();
    int col = board[0].size();
    bool ans = false;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            ans = DFS(board, word, 0, i, j, row, col, len);
            if(ans)
                return ans;
        }
    }

    return ans;
}

int main()
{
    string word = "ABCB";
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };

    bool ans = exist(board, word);

    cout << ans << endl;
    
    return 0;
}