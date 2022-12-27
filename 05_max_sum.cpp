
https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0


// memoization 

#include <bits/stdc++.h> 
int f(vector<int> &nums,map<int, int> &mp ,int idx)
{   
    if(mp[idx] != 0) return mp[idx];
    if(nums.size() <= idx) return 0;
    if(nums.size() - 1 == idx) return nums[idx];
    if(nums.size() - 1 - 1 == idx) return nums[idx];
    int l = f(nums,mp, idx + 2) + nums[idx];
    int r = f(nums,mp, idx + 3) + nums[idx];
    return mp[idx] = max(l ,r);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    map<int, int> mp;
    int ans = max(f(nums, mp, 0),f(nums, mp , 1)) ;
    return ans;
    
}


// tabulation

#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp;
    dp.push_back(nums[0]);
    if(nums.size() == 1) return dp[0];
    dp.push_back(nums[1]); 
    if(nums.size() == 2) return max(dp[0],dp[1]);
    dp.push_back(nums[0]+nums[2]);
    if(nums.size() == 3) return max(dp[2],dp[1]);
    for(int  i= 3; i < nums.size(); ++i)
    {
        dp.push_back(max(dp[i-2], dp[i-3]) + nums[i]);
    }
    return max(dp[nums.size()-1], dp[nums.size()-2]);
}
