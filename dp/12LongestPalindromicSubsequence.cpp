#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int lcs(string &s1, string &s2, int n1, int n2, vector<vector<int>> &dp)
{
    if (n1 == 0 or n2 == 0)
        return 0;
    if (dp[n1][n2] != 0)
        return dp[n1][n2];
    if (s1[n1 - 1] == s2[n2 - 1])
        return dp[n1][n2] = 1 + lcs(s1, s2, n1 - 1, n2 - 1, dp);
    return dp[n1][n2] = max(lcs(s1, s2, n1 - 1, n2, dp), lcs(s1, s2, n1, n2 - 1, dp));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n1,n2;
        string s1,s2;
        cin >> s1;
        s2 = s1;
        reverse(s2.begin(),s2.end());
        n1 = s1.length();
        n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // cout<<lcs(s1,s2,n1,n2,dp)<<endl;
        //iterative
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[n1][n2] << endl;
    }
}