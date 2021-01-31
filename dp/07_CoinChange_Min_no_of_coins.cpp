#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

int minCoins(int a[], int n, int s)
{
    long long dp[n + 1][s + 1];
    for (int i = 0; i <= s; i++)
        dp[0][i] = INT_MAX;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = min(dp[i][j - a[i - 1]] + 1, dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    long long ans = dp[n][s];
    if (ans >= INT_MAX)
        ans = -1;
    return ans;

    vector<vector<long long>> dp1(n + 1, vector<long long>(s + 1, INT_MAX));
    ans = go(a, n, s, dp1);
    if (ans >= INT_MAX)
        ans = -1;
    return ans;
}
long long go(int a[], int n, int s, vector<vector<long long>> &dp)
{
    if (s == 0)
        return 0;
    if (n <= 0)
        return INT_MAX;
    if (a[n - 1] <= s)
    {
        return dp[n][s] = min(go(a, n, s - a[n - 1], dp) + 1, go(a, n - 1, s, dp));
    }
    return dp[n][s] = go(a, n - 1, s, dp);
}
