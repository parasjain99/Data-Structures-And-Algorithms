#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
vector<int> a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,s=0,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
        s+=x;
    }
    if (n == 1){
        cout<<a[0];
        return;
    }
        
    int dp[n+1][s+1];
    vector<int> ele;
    for(int i=0;i<s;i++) dp[0][i] = false;
    for(int i=0;i<n;i++) dp[i][0] = true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(a[i-1]<=j){
                dp[i][j] = dp[i-1][j-a[i-1]] or dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
            // cout<<dp[i][j]<<" ";
            if(i==n and dp[i][j] and j<=s/2) ele.push_back(j);
        }
        // cout<<endl;
    }
    cout<<ele.size()<<endl;
    int ans = INT_MAX;
    for(int i=0;i<ele.size();i++){
        ans = min(ans,s - 2*ele[i]);
    } 
    cout<<ans;
}