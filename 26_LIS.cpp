// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/submissions/ 
class Solution
{
public:
    int f(vector<int> &nums, int i, int pre, vector<vector<int>> &dp)
    {
        if (i >= nums.size())
            return 0;
        if (dp[i][pre + 1] != -1)
            return dp[i][pre + 1];
        int ntk = f(nums, i + 1, pre, dp);
        int tk = INT_MIN;
        if (pre == -1 || nums[i] > nums[pre])
        {
            tk = 1 + f(nums, i + 1, i, dp);
        }
        return dp[i][pre + 1] = max(tk, ntk);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        
        // r3ecursion
        // o(n*n) time;
        // o(n*n) + o(n) space
        // vector<vector<int>> dp(nums.size()+10, vector<int>(nums.size()+10, -1));
        // return f(nums, 0,-1, dp);

        // o(n*n) time;
        // o(n*n) space
        // tabulation
        // not-understood

        
        
        
        
        
        
        
        
        // o(n*n) time
        // o(n) space
        vector<int> dx(n, 1);
        vector<int> print(n);
        int mx = -1;
        int idx = -1;
        for (int i = 1; i < n; ++i)
        {  
            print[i] = i;
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j] && dx[i] < dx[j] + 1)
                {
                    dx[i] = dx[j] + 1;
                    print[i] = j;
                }
            }
            if(mx < dx[i])
            {
                mx = dx[i];
                idx = i;
            }
        }
        // printing
        cout<<nums[idx]<<" ";
        while(print[idx] != idx)
        {
            cout<<nums[print[idx]]<<" ";
            idx = print[idx]; 
        }
        return mx;

        
        
        
        // binary serach problm
        // o(nlon(n)) time
        // o(n) space
        // vector<int> lis;
        // lis.push_back(nums[0]);
        // for(int i = 1; i < n; i++)
        // {
        //         if(lis.back() < nums[i]) lis.push_back(nums[i]);
        //         int idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
        //         lis[idx] = nums[i];
        // }
        // return lis.size();
    }
};
