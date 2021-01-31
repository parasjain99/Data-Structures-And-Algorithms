#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,ll> dist;
void Bellman_Ford(ll nodes, ll s, vector<tuple<ll, ll, ll>> edge){
    dist[s]=0;
    for(ll i=0;i<nodes-1;i++){
        for(auto e:edge){
            ll a,b,w;
            tie(a,b,w) = e;
            // cout<<a<<" "<<b<<" "<<w<<endl;
            dist[b] = min(dist[b],dist[a]+w);
        }
    }
}

int main()
{
    ll nodes, edges, x, y,w,s;
    cin >> nodes;
    cin >> edges;
    cin>>s; //start node
    for (ll i = 0; i < nodes; i++)
        dist[i] = INT_MAX;
    
    vector<tuple<ll,ll,ll> > edge;
    for (ll i = 0; i < edges; ++i)
    {
        // cin >> x >> y >> w;
        cin >> w >> x >> y;
        edge.push_back({x,y,w});
        edge.push_back({y,x,w}); //for undirected graph
        
    }
    Bellman_Ford(nodes,s,edge);
    for(int i=0;i<nodes;i++){
        cout<<dist[i]<<" ";
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