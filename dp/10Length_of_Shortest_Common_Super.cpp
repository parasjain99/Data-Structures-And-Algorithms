#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    	string s1,s2;
	cin>>s1>>s2;
	int n1 = s1.length(), n2 = s2.length();
	vector<vector<int> > v(n1+1,vector<int>(n2+1,0));
	for(int i=1;i<=n1;i++){
	    for(int j=0;j<=n2;j++){
	        if(s1[i-1]==s2[j-1]) v[i][j] = 1+v[i-1][j-1];
	        else v[i][j] = max(v[i-1][j],v[i][j-1]);
	    }
	}
	cout<<n1+n2-v[n1][n2]<<endl;
	}

}