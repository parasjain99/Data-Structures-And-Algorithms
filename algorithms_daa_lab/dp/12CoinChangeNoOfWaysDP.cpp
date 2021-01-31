#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sum, n;
    cin >> sum >> n;
    vector<int> a(n);
    	map<int,map<int, int> > dp;
    for (int i = 0; i < n; i++)
        cin >> a[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<=sum;j++){
                if(j==0) dp[i][j]=1;
                else if(a[i]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i][j-a[i]];
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
}