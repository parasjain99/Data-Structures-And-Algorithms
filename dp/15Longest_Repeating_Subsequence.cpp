#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2;
        string s1, s2;
        cin >> n1;
        cin >> s1;
        s2 = s1;
        n1 = s1.length();
        n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // cout<<lcs(s1,s2,n1,n2,dp)<<endl;
        //iterative
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] == s2[j - 1] and i != j) //this variation
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[n1][n2] << endl;
    }
}