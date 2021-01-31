#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
lint M = 1003;
int dp[1001][1001][2];
lint go(string &s, lint i, lint j, lint isT)
{
    if (i > j)
        return false;
    if (i == j)
    {
        if (isT)
            return (s[i] == 'T');
        else
            return (s[i] == 'F');
    }
    if(dp[i][j][isT]!=-1) return dp[i][j][isT];
    lint ans = 0,LT,LF,RT,RF;
    for (lint k = i + 1; k < j; k += 2)
    {
        if(dp[i][k-1][1]==-1) LT = go(s, i, k - 1, 1);
        else LT = dp[i][k-1][1];
        if(dp[i][k-1][0]==-1) LF = go(s, i, k - 1, 0);
        else LF = dp[i][k-1][0];
        if(dp[k+1][j][1]==-1) RT = go(s, k + 1, j, 1);
        else RT = dp[k+1][j][1];
        if(dp[k+1][j][0]==-1) RF = go(s, k + 1, j, 0);
        else RF = dp[k+1][j][0];
        if (isT)
        {
            if (s[k] == '|')
                ans = (ans + LT * RT + LT * RF + LF * RT) % M;
            else if (s[k] == '&')
                ans = (ans + LT * RT) % M;
            else if (s[k] == '^')
                ans = (ans + LT * RF + LF * RT) % M;
        }
        else
        {
            if (s[k] == '|')
                ans = (ans + LF * RF) % M;
            else if (s[k] == '&')
                ans = (ans + LF * RF + LT * RF + LF * RT) % M;
            else if (s[k] == '^')
                ans = (ans + LT * RT + LF * RF) % M;
        }
        ans = ans % M;
    }
    return dp[i][j][isT] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        lint n;
        string s;
        cin >> n;
        cin >> s;
        cout << go(s, 0, n - 1, 1) << endl;
    }
}