// https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?leftPanelTab=0


//  recursion with memoization
#include <bits/stdc++.h> 

int f(vector<vector<int>> &g,vector<vector<int>> &dp, int i , int j)
{
    
    if(i == 0 && j == 0) return g[i][j];
    if(i < 0 || j < 0) return 1e9;
    
     if(dp[i][j] != -1) return dp[i][j];
     int t = f(g, dp, i -1 , j) + g[i][j];
     int l = f(g, dp, i, j - 1) + g[i][j];
    
    return dp[i][j] = min(t, l);
    
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<int>> dp(grid.size(), vector<int>( grid[0].size(), -1));
    return  f(grid, dp, grid.size()-1, grid[0].size()-1);
}

// by tabulation

#include <bits/stdc++.h> 

int v(int i, int j, int R, int C)
{
    return ((i >= 0 && i < R && j >= 0 && j <C));
}
int minSumPath(vector<vector<int>> &grid) {
    
    vector<vector<int>> dp(grid.size(), vector<int>( grid[0].size(), 0));
    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if( i == 0 && j == 0) dp[i][j] = grid[i][j];
            if( i == 0 && j == 0) continue;
            int l = 1e9+7;
            int t = 1e9+7;
            if(v(i-1, j, m ,n)) l = dp[i-1][j];
            if(v(i, j-1, m,n)) t = dp[i][j-1];
            dp[i][j] = min(l,t) + grid[i][j];
        }
    }
    return dp[m-1][n-1];
}