    int equalPartition(int n, int a[]){
        int sum=0;
        for(int i=0;i<n;i++) sum+=a[i];
        if(sum%2!=0) return 0;
        sum = sum/2;
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) dp[i][j]=false;
                if(j==0) dp[i][j]=true;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j>=a[i-1]){
                    dp[i][j] = dp[i-1][j-a[i-1]] or dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    // cout<<dp[n][sum];
    return dp[n][sum];
    }