#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> dist;
unordered_map<ll,bool> processed;

void Dijkstra(ll nodes, int s, vector<vector<pair<ll, ll>>> adj){
    dist[s] = 0;
    priority_queue<pair<ll,ll> > q; //default max priority queue
    q.push({0,s});
    while(!q.empty()){
        int a = q.top().second; q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(auto u: adj[a]){
            int b = u.first, w = u.second;
            if(dist[a]+w<dist[b]){
                dist[b] = dist[a]+w;
                q.push({-dist[b],b}); // pushing -ve distance to work as a min priority queue
            }
        }
    }
}

int main(){
    ll nodes, edges, x, y, w, s;
    cin >> nodes;
    cin >> edges;
    cin >> s; //start node
    
    for (ll i = 0; i < nodes; i++){
        dist[i] = INT_MAX;
        processed[i] = false;
    }

    vector<vector<pair<ll,ll> > > adj(nodes);

    for (ll i = 0; i < edges; ++i)
    {
        // cin >> x >> y >> w;
        cin >> w >> x >> y;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w}); //for undirected graph
    }
    Dijkstra(nodes,s,adj);
    for (int i = 0; i < nodes; i++)
    {
        cout << dist[i] << " ";
    }
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
