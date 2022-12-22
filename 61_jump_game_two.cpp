https://leetcode.com/problems/jump-game-ii/description/
class Solution {
public:
    int f(vector<int> &n, int i, vector<int> &dp)
    {
        if(i >= n.size()) return 1e7;
        if(i == n.size()-1) return 0;
        if(dp[i] != -1) return dp[i];
        int step = 1e7;
        for(int j = 1; j <= n[i]; ++j)
        {
           step = min(step, 1 + f(n, i+j, dp));
        }
        return dp[i] = step;

    }
    int jump(vector<int>& nums) {
        vector<int> dp (nums.size(), -1);
        return f(nums, 0, dp);
    }
};