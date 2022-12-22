https://leetcode.com/problems/coin-change-ii/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(vector<int> &v,vector<vector<int>> &dp, int tar, int i)
    {
        // bs
        if(tar == 0) return 1;
        if(i == 0) {
            if(tar % v[i] == 0) return 1;
            return 0;
        };
       
        //dp
        if(dp[i][tar] != -1) return dp[i][tar];

        // cal
        int ntke = f(v, dp, tar, i - 1);
        int tk = 0;
        if(tar >= v[i]) tk = f(v, dp, tar - v[i], i);


        // re
        return  dp[i][tar] = (tk + ntke);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return f(coins, dp, amount, coins.size() - 1);
    }
};