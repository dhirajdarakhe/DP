// https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029


// memoization

#include <bits/stdc++.h> 
int f(vector<int> &p, vector<int> &wg,vector<vector<int>> &dp, int w, int i){
    
    // bs
    if(i == 0) 
    {
        if(w >= wg[0]) return p[0] * (w / wg[0]);
        return 0;
    }
    
    // dp
    if(dp[i][w] != -1) return dp[i][w];
    
    // logic
    int ntk = f(p, wg,dp, w, i - 1);
    int tk = INT_MIN;
    if(w >= wg[i]) tk = p[i] + f(p, wg, dp, w - wg[i], i);
    
    // return
    return dp[i][w] = max(tk, ntk);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{  
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return f(profit, weight, dp, w, n - 1);
    // Write Your Code Here.
}



// tabulation

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{  
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
//     return f(profit, weight, dp, w, n - 1);
    
    // bs condN
    for(int i = 0; i <= w; ++i) dp[0][i] = (i >= weight[0]) ? (profit[0] * (i / weight[0])) : 0;
    
    // lgic
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j <= w; j++)
        {
                int ntk = dp[i-1][j];
                int tk = INT_MIN;
                if(j >= weight[i]) tk = profit[i] + dp[i][ j - weight[i]];
                dp[i][j] = max(ntk, tk);
        }
    }
    return dp[n-1][w];
}
