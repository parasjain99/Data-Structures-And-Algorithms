#include<bits/stdc++.h>
using namespace std;
class item{public:
	int wt,p,index;
	bool pick=false;
};
bool mycompwt(item a, item b) { return a.wt<b.wt; } 
bool mycompind(item a, item b) { return a.index<b.index; } 
int main(){
	int wc,tp,n;
	cin>>wc>>n;
	vector<item> list(n);
	for(int i=0;i<n;i++) cin>>list[i].p>>list[i].wt, list[i].index=i;
	sort(list.begin(),list.end(),mycompwt);
	map<int, map<int, int> > dp;
	for(int i=0;i<n;i++){
		for(int j=0;j<=wc;j++){
			if(j==0) dp[i][j]=0;
			else if(j<list[i].wt) dp[i][j]=dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j],(list[i].p+dp[i-1][j-list[i].wt]));
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	int x=wc,y=n-1;
	while(x>0){
		if(dp[y][x]!=dp[y-1][x]){
			list[y].pick=true;
			x=x-list[y].wt;
		}
		y--;
	}
	sort(list.begin(),list.end(),mycompind);
	cout<<"index\tp\twt\tpicked\n";
	for(int i=0;i<list.size();i++){
		cout<<list[i].index<<"\t"<<list[i].p<<"\t"<<list[i].wt;
		if(list[i].pick) cout<<"\tyes\n";
		else cout<<"\tno\n";	
	}
	
}
//8 4
//1 6
//4 5
//3 4
//2 3
