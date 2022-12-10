// https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?leftPanelTab=1

// tabulation DP

#include <bits/stdc++.h>
int validPlace(int i, int j, int R, int C)
{
    return ((i >= 0) && (j >= 0) && (i < R) && (j < C));
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0)
                dp[0][0] = 1;
            if (validPlace(i - 1, j, m, n))
                dp[i][j] += dp[i - 1][j];
            if (validPlace(i, j - 1, m, n))
                dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

// TC > O(n*m);
// SC > O(n*m)
