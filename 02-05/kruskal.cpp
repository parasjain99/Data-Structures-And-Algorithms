#include<bits/stdc++.h>

using namespace std;
int g[100][100];

bool myfun(pair<int, pair<int,int> > a, pair<int, pair<int,int> > b){
	return (a.first<b.first);
}

bool join(vector<int> &ds, int x, int y ){
	int rx=x,ry=y;
	while(ds[rx]>=0){
		rx=ds[rx];
	}
	while(ds[ry]>=0){
		ry=ds[ry];
	}
	if(rx==ry){
		return false;
	}
	else if(ds[rx]<=ds[ry]){
		ds[rx]+=ds[ry];
		ds[ry]=rx;
		return true;
	}
	else{
		ds[ry]+=ds[rx];
		ds[rx]=ry;
		return true;
	}
	
}

void kruskal(vector<pair<int, pair< int, int> > > g, int n, int e){
	vector<int> ds(n,-1);
	vector<pair<int, pair< int, int> > > tree;
	for(int i=0;i<e;i++){
		if(join(ds,g[i].second.first,g[i].second.second)){
			tree.push_back(g[i]);
		}
	}
	int sum=0;
	for(int i=0;i<tree.size();i++){
		cout<<tree[i].second.first<<"-"<<tree[i].second.second<<" Weight "<<tree[i].first<<endl;
		sum+=tree[i].first;
	}
	cout<<"Sum of MST = "<<sum<<endl;
}

int main(){
	int n,e,x,y,w;
	vector<pair<int, pair< int, int> > > t;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		cin>>w>>x>>y;
		t.push_back({w,{x,y}});
		g[x][y]=w;
		g[y][x]=w;
	}
	sort(t.begin(),t.end(),myfun);
	kruskal(t,n,e);
	
}

// 9 14
// 1 7 6
// 2 8 2
// 2 6 5
// 4 0 1
// 4 2 5
// 6 8 6
// 7 2 3
// 7 7 8
// 8 0 7
// 8 1 2
// 9 3 4
// 10 5 4
// 11 1 7
// 14 3 5
