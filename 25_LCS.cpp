https://leetcode.com/problems/longest-common-subsequence/description/
class Solution {
public:
    int f(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
            if(i < 0 || j < 0) return 0;
            if(dp[i][j]!=-1)return dp[i][j];
            if(s[i]==t[j]) return dp[i][j]=1+f(s,t,i-1,j-1,dp);
            return dp[i][j]=max(f(s,t,i-1,j,dp), f(s,t,i,j-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));
      return f(text1,text2,n1-1,n2-1,dp);   
    }
};
