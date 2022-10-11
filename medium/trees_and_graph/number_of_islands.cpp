#include <bits/stdc++.h>
#define right 1
#define down 2
#define left 3
#define up 4

using namespace std;

int check_road(vector<vector<char>> &grid, vector<vector<bool>> &check, int r, int c)
{
    int row = grid.size();
    int col = grid[0].size();

    if((c+1) < col and grid[r][c+1] == '1' and !check[r][c+1])
        return right;
    else
        if((r+1) < row and grid[r+1][c] == '1' and !check[r+1][c])
            return down;
        else
            if((c-1) >= 0 and grid[r][c-1] == '1' and !check[r][c-1])
                return left;
            else
                if((r-1) >= 0 and grid[r-1][c] == '1' and !check[r-1][c])
                    return up;
                else
                    return 0;
}

void DFS(vector<vector<char>> &grid, vector<vector<bool>> &check, int row_s, int col_s)
{
    stack<vector<int>> dfs;
    int r = row_s, c = col_s;
    int road = check_road(grid, check, r, c);
    dfs.push({r, c, road});

    do
    {
        check[r][c] = true;
        road = check_road(grid, check, r, c);

        switch(road)
        {
        case right:
            dfs.push({r, c, road});
            c++;
            break;
        case down:
            dfs.push({r, c, road});
            r++;
            break;
        case left:
            dfs.push({r, c, road});
            c--;
            break;
        case up:
            dfs.push({r, c, road});
            r--;
            break;
        default:
            r = dfs.top()[0];
            c = dfs.top()[1];
            dfs.pop();
            break;
        }

    }while(!dfs.empty());
    
}

//上面和這個是我寫的垃圾dfs
int numIslands1(vector<vector<char>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    int ans = 0;
    vector<vector<bool>> check(row, vector<bool> (col, false));

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            if(check[i][j])
                continue;
            else
                if(grid[i][j] == '0')
                    check[i][j] = true;
                else
                {
                    DFS(grid, check, i, j);
                    ans++;
                }

    return ans;
}

//他跟我上面寫的垃圾code有兩個不同，第一:dfs用recursive的方式，不用像我一樣要去檢查每一個方向
//他不用額外的vector去存檢查過了沒，他檢查過後就把'1'改成'0'及是檢查完畢
void dfs(vector<vector<char>> &grid, int i, int j, int m, int n)
{
    if(i < 0 or j < 0 or i >= m or j >= n or grid[i][j] == '0')
        return;
    else
    {
        grid[i][j] = '0';
        dfs(grid, i, j+1, m, n);
        dfs(grid, i, j-1, m, n);
        dfs(grid, i+1, j, m, n);
        dfs(grid, i-1, j, m, n);
    }
}

int numIslands(vector<vector<char>> &grid)
{
    if(grid.empty())
        return 0;
    else
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                ans += grid[i][j] - '0';
                dfs(grid, i, j, m, n);
            }
        
        return ans;
    }
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int ans = numIslands(grid);
    cout << ans << endl;
    
    return 0;
}