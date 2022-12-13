https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTab=0


#include <bits/stdc++.h>
int minSubsetSumDifference(vector<int> &arr, int n)
{
    // Write yo code here.
    int sum = 0;
    for (auto x : arr)
        sum += x;
    int ans = INT_MAX;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 10, 0));
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= sum; ++j)
        {
            int ntk = dp[i - 1][j];
            int tk = 0;
            if (j >= arr[i - 1])
                tk = dp[i - 1][j - arr[i - 1]];
            dp[i][j] = (tk || ntk);
            if (dp[i][j])  ans = min(ans, abs((sum - j) - j));
        }
    }
    return ans == INT_MAX ? 0 : ans;
}
