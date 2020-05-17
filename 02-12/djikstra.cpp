#include<bits/stdc++.h>
using namespace std;
int G[100][100];

void dijkstra(int n, int e, int s){
	vector<int> arr(n,10000001); // for storing distance
	priority_queue<pair<int, int> > Q; //distance, node
	int p = s;
	arr[s]=0;
	Q.push({0,s});
	while(!Q.empty()){
			pair<int, int> P = Q.top();
			Q.pop();
			p=P.second;	
		for(int i=0;i<n;i++){
			if((G[p][i]!=0)&&(arr[i]>(G[p][i]+arr[p]))){
				arr[i] = G[p][i]+arr[p];
				Q.push({arr[i],i});
			}
		}
				
	}
	for(int i=0;i<n;i++){
		cout<<i<<" "<<arr[i]<<endl;
	}
}

int main(){
	int n,e,w,x1,x2,s;
	cin>>n>>e>>s;
	for(int i=0;i<e;i++){
		cin>>w>>x1>>x2;
		G[x1][x2]=w;
		G[x2][x1]=w;
	}
	dijkstra(n,e,s);
}
/*
9 14 0
1 7 6
2 8 2
2 6 5
4 0 1
4 2 5
6 8 6
7 2 3
7 7 8
8 0 7
8 1 2
9 3 4
10 5 4
11 1 7
14 3 5

output

0 0
1 4
2 12
3 19
4 21
5 11
6 9
7 8
8 14

*/
