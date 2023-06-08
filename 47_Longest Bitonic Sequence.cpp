#include <bits/stdc++.h> 
vector<int> dp(vector<int> &arr, vector<int>&dx , int n)
{
	for(int i=0;i<n;++i) for(int j=0;j<i;++j) if(arr[i]>arr[j]) dx[i] = max(dx[i], dx[j]+1);
	return dx;
}
int longestBitonicSequence(vector<int>& arr, int n) {
	  // Write your code here.
	vector<int> dx1(n, 1), dx2(n, 1);
	dx1 = dp(arr, dx1, n);
	reverse(arr.begin(), arr.end());
	dx2 = dp(arr, dx2, n);
	reverse(dx2.begin(), dx2.end());
	int mx = -1;
	for(int i=0;i<n;++i)  mx = max(mx, dx1[i]+dx2[i]-1);
	return mx;	 
} 
