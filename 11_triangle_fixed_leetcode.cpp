#include <bits/stdc++.h>
using namespace std;


//  by momization 

class Solution
{
public:
    int f(vector<vector<int>> &t, vector<vector<int>> &dp, int r, int c)
    {
        if (r >= t.size())
            return 0;
        if (dp[r][c] != -1)
            return dp[r][c];
        return dp[r][c] = min(f(t, dp, r + 1, c) + t[r][c], f(t, dp, r + 1, c + 1) + t[r][c]);
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), -1));
        return f(triangle, dp, 0, 0);
    }
};


// tabulation 

class Solution {
public:
    
    int v(int i, int j, int r, int c)
    {
        return ((i >= 0) && ( i < r) && (j >= 0) && ( j < c));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size()-1].size(), 0));
    int ans = INT_MAX;
      for(int i = 0; i < triangle.size(); ++i)
      {
          for(int j = 0; j < triangle[i].size(); ++j)
          {
              if(i == 0 && j == 0) dp[i][j] = triangle[i][j] ;
              if(i == 0 && j == 0) continue;
              int ul = INT_MAX;
              int ur = INT_MAX;
              if(v(i-1, j-1,triangle.size(),triangle[i-1].size())) ul = dp[i-1][j-1];
              if(v(i-1, j,triangle.size(),triangle[i-1].size())) ur = dp[i-1][j];
              dp[i][j] = min(ur, ul)+triangle[i][j];
          }
      }
      return *min_element(dp[triangle.size()-1].begin(), dp[triangle.size()-1].end()); 


    }
}; 