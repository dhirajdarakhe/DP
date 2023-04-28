// https://leetcode.com/problems/edit-distance/
class Solution {
public:
    int f(string &s1, string &s2, int i, int j,vector<vector<int>> &dp)
{
    if(i >= s1.size()) return s2.size() - j;
    if( j >= s2.size()) return s1.size()-i ;
    int mx = 1e9+10;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j])
    {
        mx = min(mx, f(s1, s2, i+1, j+1, dp));
    } 
    else
    {
       mx = min(mx, f(s1, s2, i+1, j+1, dp) + 1); // replace
       mx = min(mx, f(s1, s2, i, j+1, dp) + 1);  //  insert
       mx = min(mx, f(s1, s2, i+1, j, dp)+ 1);  // delete
    }
    return dp[i][j] = mx;
}
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(1010, vector<int>(1101, -1));
        return f(word1, word2, 0, 0, dp);
        
    }
};
