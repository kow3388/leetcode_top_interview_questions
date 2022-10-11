#include <bits/stdc++.h>

using namespace std;

//這個方法在數字大的時候會overflow，所以無法使用
int uniquePaths1(int m, int n)
{
    m = m - 1;
    n = n - 1;
    unsigned long long int ans = 1;

    // (m+n)!/(m!*n!)
    if(n > m)
        swap(m, n);
    
    for(int i = (m+n); i > m; i--)
        ans *= i;

    for(int i = 1; i <= n; i++)
        ans /= i;

    return ans;
}

//用recursive會time out
void walkpath(int m, int n, int &ans)
{
    if(m == 0 and n == 0)
        ans++;
    else if(m == 0 and n != 0)
        walkpath(m, n - 1, ans);
    else if(m != 0 and n == 0)
        walkpath(m - 1, n, ans);
    else
    {
        walkpath(m, n - 1, ans);
        walkpath(m - 1, n, ans);
    }
}

int uniquePaths2(int m, int n)
{
    m = m - 1;
    n = n - 1;
    int ans = 0;

    walkpath(m , n , ans);

    return ans;
}

//dynamic programming我沒想出來
//用dynamic programming
//記錄每一格的路徑數
//每一格的路徑數 = 上面一格的路徑數 + 左邊一格的路徑數
int uniquePaths(int m, int n)
{
    vector<vector<int>> path(n, vector<int>(m, 0));

    //第一row和第一col initial 為 1
    for(int i = 0; i < n; i++)
        path[i][0] = 1;
    for(int i = 0; i < m; i++)
        path[0][i] = 1;
    
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            path[i][j] = path[i-1][j] + path[i][j-1];
    
    return path[n-1][m-1];
}

int main()
{
    int m = 3;
    int n = 7;
    int ans = uniquePaths(m, n);

    cout << ans << endl;

    return 0;
}