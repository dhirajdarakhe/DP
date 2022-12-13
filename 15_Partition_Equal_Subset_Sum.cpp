https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?leftPanelTab=0

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (auto x : arr)
        sum += x;
    if (sum & 1)
        return 0;
    sum /= 2;
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
        }
    }
    return dp[n][sum];
}
