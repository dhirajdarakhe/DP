class Solution
{
public:
    int findNumberOfLIS(vector<int> &arr)
    { //https://leetcode.com/problems/number-of-longest-increasing-subsequence/
        int n = arr.size();
        vector<int> dx(n, 1);
        vector<int> ct(n, 1);
        int idx = -1;
        int mx = 1;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (arr[i] > arr[j] && dx[i] < dx[j] + 1)
                {
                    dx[i] = dx[j] + 1;
                    ct[i] = ct[j];
                }
                else if (arr[i] > arr[j] && dx[i] == dx[j] + 1)
                    ct[i] += ct[j];
            }
            mx = max(mx, dx[i]);
        }
        for(int i =0;i<n;++i)
            if(dx[i]==mx) ans+=ct[i];
        return ans;
    }
};
