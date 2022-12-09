
// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0

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