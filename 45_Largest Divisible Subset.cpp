#include <bits/stdc++.h> 
vector<int> divisibleSet(vector<int> &arr){//https://www.codingninjas.com/codestudio/problems/divisible-set_3754960?leftPanelTab=0
    // Write your code here.
        // o(n*n) + o(nlon) time
        // o(3*n) space
        int n = arr.size();
        vector<int> dx(n, 1);
        vector<int> print(n);
        vector<int> ans;
        sort(arr.begin(), arr.end());
        int mx = -1;
        int idx = -1;
        for (int i = 0; i < n; ++i)
        {  
            print[i] = i;
            for (int j = 0; j < i; ++j)
            {
                if (arr[i] % arr[j] == 0 && dx[i] < dx[j] + 1)
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
        // cout<<arr[idx]<<" ";
        ans.push_back(arr[idx]);
        while(print[idx] != idx)
        {
            // cout<<arr[print[idx]]<<" ";
            ans.push_back(arr[print[idx]]);
            idx = print[idx]; 
        }
        return ans;
}
