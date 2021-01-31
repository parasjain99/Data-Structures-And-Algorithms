#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
//Number of ways recursive
long long int count(int a[], int n, int s)
{

    vector<vector<long long>> dp(n + 1, vector<long long>(s + 1, -1));

    //   return go(a,n,s,dp);
}
long long int go(int a[], int n, int s, vector<vector<long long>> &dp)
{
    if (s == 0)
        return 1;
    if (n <= 0 or s < 0)
        return 0;
    if (dp[n][s] != -1)
        return dp[n][s];
    if (s >= a[n - 1])
        return dp[n][s] = go(a, n, s - a[n - 1], dp) + go(a, n - 1, s, dp);
    return dp[n][s] = go(a, n - 1, s, dp);
}

//Iterative

long long int count(int a[], int n, int s)
{

    long long dp[n + 1][s + 1];
    for (int i = 0; i <= s; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (j >= a[i - 1])
                dp[i][j] = dp[i][j - a[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][s];

    //   vector<vector<long long> > dp(n+1,vector<long long>(s+1,-1));
    //   return go(a,n,s,dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

}
