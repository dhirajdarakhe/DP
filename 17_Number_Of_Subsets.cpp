// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?leftPanelTab=0

// memoization

#include <bits/stdc++.h>
int f(vector<int> &num, vector<vector<int>> &dp, int sum, int i)
{
    if (sum == 0)
        return 1;
    if (i == 0)
        return (sum == num[0]);
    if (dp[i][sum] != -1)
        return dp[i][sum];
    int nttk = f(num, dp, sum, i - 1);
    int tk = 0;
    if (sum >= num[i])
        tk = f(num, dp, sum - num[i], i - 1);
    return dp[i][sum] = (nttk + tk);
};
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n + 1, vector<int>(tar + 1, -1));
    return f(num, dp, tar, num.size() - 1);
}

// tc = o(n*tar);
// sc = o(n*tar)+o(n);

// tabulation

#include <bits/stdc++.h>
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n + 1, vector<int>(tar + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= tar; ++j)
        {
            dp[i][j] += dp[i - 1][j];
            if (num[i - 1] <= j)
                dp[i][j] += dp[i - 1][j - num[i - 1]];
        }
    }
    return dp[n][tar];
}

// tc = o(n*tar);
// sc = o(n*tar);

#include <bits/stdc++.h>
int minSubsetSumDifference(vector<int> &arr, int n)
{
    // Write yo code here.
    int sum = 0;
    for (auto x : arr)
        sum += x;
    vector<vector<int>> dp(n + 1, vector<int> (sum + 1 , 0);
    for(int i = 0 ; i < n; ++i) dp[i][0] = 1;
    
             for(int i = 1; i <= n; ++i)
                               {
        for (int j = 0; j <= sum; ++j)
        {
            int ntk = dp[i - 1][j];
            int tk = 0;
            if (j >= arr[i - 1])
                tk = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            dp[i][j] = (tk || ntk);
        }
                               }
}
