#include<bits/stdc++.h>
using namespace std;
map<int,map<int,int> > dp;
int go(int sum, int n, vector<int> &a){
	if(sum!=0&&n==0) dp[sum][n] = 1e5;
	else if(sum<0) dp[sum][n] = 1e5;
	else if (sum == 0) return 0;
	else if(sum<a[n-1]) dp[sum][n] = go(sum, n - 1, a);
	else dp[sum][n] = min(1 + go(sum - a[n - 1], n, a), go(sum, n - 1, a));
	return dp[sum][n];

}
int main(){
	int sum,n;
	cin>>sum>>n;
	vector<int> a(n);
//	map<int,map<int, bool> > dp;
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<go(sum,n,a);
}

// 11 5
// 2 3 7 8 10
