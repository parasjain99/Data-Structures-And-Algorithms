#include<bits/stdc++.h>
using namespace std;
void prims(int v, int e, vector<vector<int>> &graph)
{
	vector<int> viz(v, 0), dis(v, INT_MAX),par(v);
	par[0]=0;     
	dis[0] = 0;
	for (int i = 0; i < v; i++)
	{
		int ind = -1, min_val = INT_MAX;
		for (int j = 0; j < v; j++)
		{
			if (viz[j] == 0 && dis[j] < min_val)
			{
				ind = j;
				min_val = dis[j];
			}
		}
		viz[ind] = 1;
		for (int j = 0; j < v; j++)
		{
			if (graph[ind][j] != INT_MAX && viz[j] == 0 && dis[j] > graph[ind][j])
				{
					dis[j] = graph[ind][j];
					par[j] = ind;
				}
		}
	}
	int sum = 0;
	for (int i = 1; i < v; i++){
		sum += dis[i];
		cout<<i<<"-"<<par[i]<<" Weight="<<dis[i]<<endl;
	}
	cout<<"Weight of MST = "<<sum<<endl;
}

int main(){
	int n,e,w,x1,x2;
	cin>>n>>e;
	vector<vector<int>> G(n, vector<int>(n,INT_MAX));
	for(int i=0;i<e;i++){
		cin>>w>>x1>>x2;
		G[x1][x2] = w;
		G[x2][x1] = w;
	}
	prims(n,e,G);
	
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
