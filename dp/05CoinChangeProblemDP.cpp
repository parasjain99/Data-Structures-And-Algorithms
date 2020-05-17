#include<bits/stdc++.h>
using namespace std;

int main(){
	int s,n,i,j;
	cin>>s>>n;
	vector<int> a(n);
	for(i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	map<int, map<int, int> > dp;
	for(i=1;i<=s;i++) dp[-1][i]=1e5;
	for(i=0;i<n;i++){
		for(j=1;j<=s;j++){
			if(j<a[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=min(dp[i-1][j],1+dp[i][j-a[i]]);
//			cout<<dp[i][j]<<" ";
		}
//		cout<<endl;
	}
	i=n-1;
	j=s;
	
	while(i>=0&&j>=0){
		if(dp[i][j]!=dp[i-1][j]){
			cout<<a[i]<<",";
			j=j-a[i];
		}
		else i--;
	}
}

