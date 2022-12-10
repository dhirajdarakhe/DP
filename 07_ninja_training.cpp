
// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?leftPanelTab=0

// little hard problem

#include <bits/stdc++.h>

int f(int n, vector<vector<int>> &p, int idx, int iidx, vector<vector<int>> &dp)
{
    // 1 2 5
    // 3 1 1
    // 3 3 3
    if (idx + 1 >= n)   return 0;
    if (dp[idx][iidx] != -1)  return dp[idx][iidx];
    int mx = INT_MIN;
    for (int i = 0; i < p[idx + 1].size(); ++i)  if (i != iidx)
    mx = max(mx, f(n, p, idx + 1, i, dp) + p[idx + 1][i]);
    return dp[idx][iidx] = mx;
}
int ninjaTraining(int n, vector<vector<int>> &point)
{
    // Write your code here.
    int ans = INT_MIN;
    vector<vector<int>> dp(n + 10, vector<int>(point[0].size() + 10, -1));
    for (int i = 0; i < point[0].size(); ++i)
        ans = max(ans, f(n, point, 0, i, dp) + point[0][i]);
    return ans;
}