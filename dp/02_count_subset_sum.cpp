int perfectSum(int a[], int n, int sum)
	{
	    long long m = 1e9+7;
        long long dp[n+1][sum+1];
        for(int i=0;i<=sum;i++) dp[0][i] = 0;
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j>=a[i-1]){
                    dp[i][j] = (dp[i-1][j-a[i-1]] + dp[i-1][j])%m;
                }
                else dp[i][j] = dp[i-1][j];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        // cout<<dp[n][sum];
        return dp[n][sum];
	}
    //recursive soln
int a[];
int subsetSum(int n, int sum){
    if(sum==0) return 1;
    else if(n==0 or sum<0) return 0;
    if(a[n-1]<=sum) return subsetSum(n-1,sum-a[n-1]) + subsetSum(n-1,sum);
    else return subsetSum(sum,n-1);
}