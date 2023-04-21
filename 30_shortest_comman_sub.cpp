// https://leetcode.com/problems/shortest-common-supersequence/
class Solution
{
public:
    string shortestCommonSupersequence(string &s1, string &s2)
    {
        vector<vector<int>> dp(1010, vector<int>(1010, 0));
        for (int i = 1; i <= s1.size(); ++i)
        {
            for (int j = 1; j <= s2.size(); ++j)
            {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
         for (int i = 1; i <= s1.size(); ++i)
        {
            for (int j = 1; j <= s2.size(); ++j)
            {
                cout<<dp[i][j]<<" ";
            }
             cout<<endl;
        }
        string ans = "";
        int i = s1.size();
        int j = s2.size();
        while (i >= 1 && j >= 1)
        {
            cout<<i <<"  ^  " << j <<endl;
            if (s1[i-1] == s2[j-1])
            {
                ans += s1[i-1];
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                {
                    ans += s1[i-1];
                    i--;
                }else
                {
                    ans += s2[j-1];
                    j--;
                }
            }
        }
        cout<<i<<" " << j <<endl;
        while(i > 0)
        {
            ans += s1[i-1];
            i--;
        }
        while(j > 0)
        {
            ans +=s2[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
