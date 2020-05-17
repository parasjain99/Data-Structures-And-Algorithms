#include<bits/stdc++.h>
using namespace std;
int mat[100][100]={0};
bool myfun(pair < int, pair <int,int> > a, pair <int, pair <int,int> > b){
	return a.first>b.first;
}
void prims(vector< pair<int, pair< int, int> > > G, int n, int e){
	bool arr[n] = {false};
	arr[0]=true;
	int sel_node=0;
	vector <pair<int, pair< int, int> > > Q;
	pair<int, pair<int,int> > P;
	vector< pair<int, pair< int, int> > > T;
	bool f=true; //selected node
	do{
		if(f){
			for(int i=0;i<n;i++){
				if(mat[sel_node][i]!=0){
					Q.push_back({mat[sel_node][i],{sel_node,i}});
					mat[i][sel_node]=0;
					mat[sel_node][i]=0;
				}	
			}
		}	
		sort(Q.begin(),Q.end(),myfun);
		P=Q[Q.size()-1];
		Q.pop_back();
		if(arr[P.second.first]!=true||arr[P.second.second]!=true){
			if(arr[P.second.first]==false){
				sel_node = P.second.first;
			}
			else{
				sel_node = P.second.second;
			}
			arr[P.second.first]=true;
			arr[P.second.second]=true;
			T.push_back(P);
			f=true;
		}
		else{
			f = false;
		}
	}
	while(!Q.empty());
	cout<<endl;
	sort(T.begin(),T.end());
	for(int i=0;i<T.size();i++){
		cout<<T[i].first<<" "<<T[i].second.first<<" "<<T[i].second.second<<endl;
	}
	
}

int main(){
	vector< pair<int, pair< int, int> > > G;
	int n,e, x1,x2,w;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		cin>>w>>x1>>x2;
		G.push_back({w,{x1,x2}});
		mat[x1][x2] = w;
		mat[x2][x1] = w;
	}
	prims(G,n,e);
	
}



