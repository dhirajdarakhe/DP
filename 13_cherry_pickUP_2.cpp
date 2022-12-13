https://leetcode.com/problems/cherry-pickup-ii/description/

#include <bits/stdc++.h>
using namespace std;


// memoization

class Solution
{
public:
    int dj[3] = {-1, 0, 1};
    int f(vector<vector<int>> &g, int i, int j, int r, vector<vector<vector<int>>> &dp)
    {
        if (r == g.size())  return 0;
        if (i < 0 || j < 0 || i >= g[0].size() || j >= g[0].size())  return -1e8;
        int ans = -1e7;
        if (dp[r][i][j] != -1)   return dp[r][i][j];
        for (int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                if (i == j)  ans = max(ans, f(g, i + dj[x], j + dj[y], r + 1, dp) + g[r][j]);
                else   ans = max(ans, f(g, i + dj[x], j + dj[y], r + 1, dp) + g[r][i] + g[r][j]);
            }
        }
        return dp[r][i][j] = ans;
    }
    int cherryPickup(vector<vector<int>> &g)
    {
        // 3D vector
        vector<vector<vector<int>>> dp(g.size(), (vector<vector<int>>(g[0].size(), (vector<int>(g[0].size(), -1)))));
        return f(g, 0, g[0].size() - 1, 0, dp);
    }
};


// tc O(3^n*3^n);
// sc O(n);