#include<bits/stdc++.h>
using namespace std;
class item{public:
	int wt,p,index;
	bool pick=false;
};

bool mycompwt(item a, item b) { return a.wt<b.wt; } 
bool mycompind(item a, item b) { return a.index<b.index; }

int ks(int wt, vector<item> &list, int n){
	if(wt==0||n==0) return 0;
	if(list[n-1].wt>wt) return ks(wt, list, n-1);
	else return max(ks(wt,list,n-1),list[n-1].p+ks(wt-list[n-1].wt,list,n-1));
}

int main(){
	int wc,tp,n;
	cin>>wc>>n;
	vector<item> list(n);
	for(int i=0;i<n;i++) cin>>list[i].p>>list[i].wt, list[i].index=i;
	sort(list.begin(),list.end(),mycompwt);
	tp=ks(wc,list,n);
	cout<<tp;
	
}
//8 4
//1 6
//4 5
//3 4
//2 3
