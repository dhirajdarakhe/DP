https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?leftPanelTab=0


int validPlace(int i, int j, int R, int C)
{
    return ((i >= 0) && (j >= 0) && (i < R) && (j < C));
}
const long long MOD = 1000000007;
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    int n1 = mat.size();
    int m1 = mat[0].size();
    m = n1;
    n = m1;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (mat[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
                dp[0][0] = 1;
            if (validPlace(i - 1, j, m, n))
                dp[i][j] += dp[i - 1][j];
            if (validPlace(i, j - 1, m, n))
                dp[i][j] += dp[i][j - 1];

            dp[i][j] = dp[i][j] % MOD;
        }
    }
    return dp[m - 1][n - 1] % MOD;
}