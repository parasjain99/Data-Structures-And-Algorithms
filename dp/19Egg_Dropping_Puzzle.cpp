#include<bits/stdc++.h>
using namespace std;

/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
  
int go(int n, int k, vector<vector<int>> &dp){
    if(n==1) return k;
    if(k==0 or k==1) return k;
    if(dp[n][k]!=-1) return dp[n][k];
    int mn = INT_MAX;
    for(int i=1;i<=k;i++){
        int temp = 1 + max(go(n-1,i-1,dp),go(n,k-i,dp));
        mn = min(temp,mn);
    }
    return dp[n][k]=mn;
}

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;

        //calling function eggDrop()
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        cout<<go(n, k,dp)<<endl;
    }
    return 0;
}