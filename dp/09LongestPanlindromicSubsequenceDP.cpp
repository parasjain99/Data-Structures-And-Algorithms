#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int n=s.length();
	int dp[n][n]={0};
//	map<int,map<int,int> > dp;
	for(int i=0;i<n;i++) dp[i][i]=1;
	for(int i=1;i<n;i++){
		for(int j=0;i+j<n;j++){
			if(s[j]==s[i+j]) dp[j][i+j]=2+dp[j+1][i+j-1];
			else dp[j][i+j] = max(dp[j+1][i+j],dp[j][i+j-1]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
		cout<<endl;
	}
}
