#include <bits/stdc++.h> 
bool cmp(string x , string y){
    return x.size() < y.size();
}//https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111?leftPanelTab=0
bool f(string x , string y)
{
     int i = 0;
     int j = 0;
     int n = x.size();
     int m = y.size();
     if(n-m != 1) return 0;
     while(i < n &&  j < m)
     {
         if(x[i] == y[j])
         {
             i++;
             j++;
         }
         else
         {
            i++;
         }
     }
     if(i == n && j == m) return true;
     if(i == n-1 && j == m) return true;
     return false;

}
int longestStrChain(vector<string> &arr)
{
    // Write your code here.
    

        int n = arr.size();
        vector<int> dx(n, 1);
        sort(arr.begin(), arr.end(), cmp);
        int mx = 1;
        // for(auto x : arr) cout<<x<<" ";
        // cout<<endl;
        int idx = -1;
        for (int i = 0; i < n; ++i)
        {  
            for (int j = 0; j < i; ++j)
                if (f(arr[i], arr[j]) && dx[i] < dx[j] + 1)
                    dx[i] = dx[j] + 1;
            if(mx < dx[i])
                mx = dx[i];
        }
        return mx;
}
