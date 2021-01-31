#include<bits/stdc++.h>
using namespace std;

int main(){
	int sum,n;
	cin>>sum>>n;
	int a[n];
	map<int,map<int, bool> > dp;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<=sum;j++){
			if(j==0) dp[i][j]=true;
			else if(a[i]==j) dp[i][j]=true;
			else if(a[i]>j) dp[i][j]=dp[i-1][j];
			else dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i]];
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	int x=sum, y=n-1;
	vector<int> v;
	while(dp[y][x]==1&&x>0){
		if(dp[y][x]!=dp[y-1][x]){
			v.push_back(a[y]);
			x=x-a[y];
		}
		y--;
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i];
		if(i!=v.size()-1) cout<<"+";
	} 
}

//11 5
//2 3 7 8 10
