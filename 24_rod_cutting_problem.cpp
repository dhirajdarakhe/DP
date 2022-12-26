// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?leftPanelTab=0

int f(vector<int> &p, vector<vector<int>> &dp, int n, int i)
{
    // bs
    if (n == 0)
        return 0;
    if (i == 0)
    {
        return p[0] * n;
    }

    // dp
    if (dp[i][n] != -1)
        return dp[i][n];

    // logic
    int nt = f(p, dp, n, i - 1);
    int t = INT_MIN;
    if (n >= i + 1)
        t = p[i] + f(p, dp, n - (i + 1), i);

    // return
    return dp[i][n] = max(t, nt);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f(price, dp, n, n - 1);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; ++i)
        dp[0][i] = price[0] * (i);
    for (int i = 1; i < n; ++i) // length of rods which can be used for making rad of length N
    {
        for (int N = 0; N <= n; ++N) // length of lod to be made
        {
            int ntk = dp[i - 1][N];
            int tk = INT_MIN;
            if (N >= i + 1)
                tk = price[i] + dp[i][N - (i + 1)];
            dp[i][N] = max(tk, ntk);
        }
    }
    return dp[n - 1][n];
}