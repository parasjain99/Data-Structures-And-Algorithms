#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

int mcm(vector<int> &a, int i, int j, vector<vector<int> > &dp){
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mn = INT_MAX;
    for(int k = i;k<j;k++){
        int temp = mcm(a,i,k,dp) + mcm(a,k+1,j) + a[i-1]*a[k]*a[j];
        mn = min(temp,mn);
    }
    return dp[i][j] = mn;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
        cout<<mcm(a,1,n-1,dp)<<endl;
    }
}