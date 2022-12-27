#include <bits/stdc++.h>
using namespace std;

// Method 1 : By Recursion

int fibonicci(int n)
{
    if (n <= 1) return n;
    return fibonicci(n - 1) + fibonicci(n - 2);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << fibonicci(n);
    return 0;
}

// TC EXPONTIAL TIME COMPXITY


// Method 2 : By Recursion with memoization

int fibonicci(int n, vector<int> &dp)
{
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibonicci(n - 1,dp ) + fibonicci(n - 2, dp);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fibonicci(n, dp);
    return 0;
}

// TC O(n);
// SC O(n)+o(n)

// Method 3 :

// A )  By Recursion with Tabulation [SC O(n)];

        int fibonicci(int n, vector<int> &dp)
        {
            dp[0] = 0;
            dp[1] = 1;
            for (int i = 2; i <= n; ++i)
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
        }
        signed main()
        {
        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif
            int n;
            cin >> n;
            vector<int> dp(n + 1, -1);
            cout << fibonicci(n, dp);
            return 0;
        }


        // TC O(n);
        // SC O(n);


// b )  By Recursion with Tabulation [SC O(1)];

        int fibonicci(int n)
        {
            int dp0 = 0;
            int dp1 = 1;
            int dpi = -1;
            for (int i = 2; i <= n; ++i)
            {
                dpi = dp0 + dp1;
                dp0 = dp1;
                dp1 = dpi;
            }
            return dpi;
        }
        signed main()
        {
        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif
            int n;
            cin >> n;
            cout << fibonicci(n);
            return 0;
        }

        // TC O(n);
        // SC O(1);
