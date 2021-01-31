#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
// recursive +memo
int knapSack(int n, int w, int val[], int wt[])
{
    // int dp[n+1][w+1];
    // memset(dp,-1,sizeof(dp));
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
    return go(n, w, val, wt, dp);
}
int go(int n, int w, int val[], int wt[], vector<vector<int>> &dp)
{
    if (n <= 0 or w <= 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (wt[n - 1] <= w)
    {
        return dp[n][w] = max(val[n - 1] + go(n, w - wt[n - 1], val, wt, dp), go(n - 1, w, val, wt, dp));
    }
    else
        return dp[n][w] = go(n - 1, w, val, wt, dp);
}

//Bottom up

int knapSackIter(int n, int w, int val[], int wt[])
{
    int dp[n + 1][w + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w, x;
    int v[n], wt[n];
    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>wt[i];
    }
    cout << knapSack(n,w,v,wt);
}