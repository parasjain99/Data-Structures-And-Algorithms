#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dist[1000][1000];

void Floyd_Warshall(int n, vector<vector<pair<ll, ll> > > &adj){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main(){
    ll nodes, edges, x, y, w, s;
    cin >> nodes;
    cin >> edges;

    for (ll i = 0; i < nodes; i++){
        for(ll j=0;j<nodes;j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INT_MAX;
        }
    }
    vector<vector<pair<ll, ll>>> adj(nodes);
    for (ll i = 0; i < edges; ++i){
        // cin >> x >> y >> w;
        cin >> w >> x >> y;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w}); //for undirected graph
        dist[x][y] = w;
        dist[y][x] = w; //for undirected graph
    }
    Floyd_Warshall(nodes, adj);
    for (ll i = 0; i < nodes; i++)
    {
        for (ll j = 0; j < nodes; j++) 
            cout<<i<<" to "<<j<<" : "<<dist[i][j]<<endl;
        
    }
}

/*
9 14
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
