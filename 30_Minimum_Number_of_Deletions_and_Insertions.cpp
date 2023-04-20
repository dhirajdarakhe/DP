
// https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?leftPanelTab=1

#include <bits/stdc++.h> 
int f(string &s, string &p, int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if(i >= n || j >= m ) return 0;
    int ans = 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == p[j]) ans = f(s, p, i +1 , j +1, n , m, dp) + 1 ;
    else ans = max(f(s, p, i+1, j, n, m, dp), f(s,p,i,j+1, n, m, dp));
    return dp[i][j] = ans;

}
int canYouMake(string &str, string &ptr)
{
    vector<vector<int>> dp(str.size()+10, vector<int> (ptr.size()+ 10, 0));
    int ans  = 0;
    // = f(str, ptr,0,0,str.size(), ptr.size(), dp);
    for(int i =1; i <= str.size(); ++i)
    {
        for(int j  =1; j <= ptr.size(); ++j)
        {
            if(str[i-1]==ptr[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            ans = max(ans, dp[i][j]);
        }
    }
    ans = dp[str.size()][ptr.size()];
    ans = str.size() + ptr.size() - (2 * ans);
    return ans;
    // Write your code here.
} 
