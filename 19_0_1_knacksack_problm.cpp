// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?leftPanelTab=0

// recursion

#include <bits/stdc++.h>
int f(vector<int> &w, vector<int> &v, int i, int t)
{

    if (i == 0)
    {
        if (t >= w[i])
            return v[0];
        return 0;
    }
    int not_take = 0 + f(w, v, i - 1, t);
    int take = INT_MIN;
    if (t >= w[i])
    {
        take = v[i] + f(w, v, i - 1, t - w[i]);
    }
    return max(take, not_take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return f(weight, value, n - 1, maxWeight);
}

// TC - O ( 2 ^ n);
// SC - O ( N ) + ( 2 ^ n);

// memoization

#include <bits/stdc++.h>
int f(vector<int> &w, vector<int> &v, vector<vector<int>> &dp, int i, int t)
{

    if (i == 0)
    {
        if (t >= w[i])
            return v[0];
        return 0;
    }
    if (dp[i][t] != -1)
        return dp[i][t];
    int not_take = 0 + f(w, v, dp, i - 1, t);
    int take = INT_MIN;
    if (t >= w[i])
    {
        take = v[i] + f(w, v, dp, i - 1, t - w[i]);
    }
    return dp[i][t] = max(take, not_take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return f(weight, value, dp, n - 1, maxWeight);
}

// TC - O ( N * TARGET);
// SC - O ( N ) + O ( N * TARGET );

// A : TABULATION

#include <bits/stdc++.h>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));
    for (int item = 0; item <= n; ++item)
    {
        for (int remained_size = 0; remained_size <= maxWeight; ++remained_size)
        {

            // if total items are zero then box will carry 0 val_item
            // OR
            // if remained_sized of box is zero then box will carry 0 val_item
            if (item == 0 || remained_size == 0)
                dp[i][j] = 0;

            // if the item we want to put in box whose size is more than box remained_size
            // then I'll we are not gonna put that item , we will just carry prior items
            else if (weight[i - 1] > remained_size)
                dp[i][j] = dp[i - 1][j];

            // if the item we want to put in box whose size is enough to carry in  box of remained_size
            // then I'll we are gonna put max of ( that item +  we will add item in remained box as well ) and
            // prior items
            else
                dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[maxWeight - weight[i - 1]]);
        }
    }
    return dp[n - 1][maxWeight - 1];
}

// TC - O ( N * TARGET );
// SC - O ( N * TARGET );

// B : TABULATION

#include <bits/stdc++.h>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> dp(maxWeight + 1, 0);
    for (int item = 0; item <= n; ++item)
    {
        for (int remained_size = maxWeight; remained_size >= 0; --remained_size)
        {
            if (item == 0 || remained_size == 0)
                dp[j] = 0;
            int not_tke = dp[j];
            int tke = INT_MIN;
            if (maxWeight >= w[i - 1])
                tke = max(dj[j], value[i - 1] + dp[maxWeight - weight[i - 1]]);
            dp[j] = max(tke, not_tke);
        }
    }
    return dp[maxWeight - 1];
}

// TC - O ( N * TARGET );
// SC - O ( TARGET );