#include <bits/stdc++.h>
using namespace std;
vector<int> val,wt;
int dp[1001][1001];
int go(int n, int w){
    if(n==0 or w==0) return 0;
    if(dp[n][w]!=0) return dp[n][w];
    if(wt[n-1]<=w){
        return dp[n][w]=max(val[n-1]+go(n-1,w-wt[n-1]),go(n-1,w));
    }
    else return dp[n][w]=go(n-1,w);
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    val.clear();
	    wt.clear();
	    int n,w,x;
	    cin>>n>>w;
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<n;i++){
	        cin>>x;
	        val.push_back(x);
	    }
	    for(int i=0;i<n;i++){
	        cin>>x;
	        wt.push_back(x);
	    }
	   // cout<<go(n,w)<<endl;
	   for(int i=1;i<=n;i++){
	       for(int j=1;j<=w;j++){
	           if(wt[i-1]<=j){
	               dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
	           }
	           else dp[i][j] = dp[i-1][j];
			   cout<<dp[i][j]<<" ";
	       }
		   cout<<endl;
	   }
	   cout<<dp[n][w]<<endl;
	}
}