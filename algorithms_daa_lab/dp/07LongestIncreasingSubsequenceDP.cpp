#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,lis=0;
	cin>>n;
	vector<int> a(n),dp(n,1);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);
		}
		if(lis<dp[i]) lis=dp[i];
	}
	cout<<lis;
}
