#include<bits/stdc++.h>
using namespace std;

bool visited[100000];
void dfs(int s, vector<vector<int> > &adj)
{
    if(visited[s]) return;
    visited[s] = true;
    for (int i = 0; i < adj[s].size(); ++i)
        dfs(adj[s][i],adj);
}


int main(){
    int nodes, edges, x, y, connectedComponents = 0;
    cin >> nodes;
    cin >> edges; 
    vector<vector<int> > adj(nodes);
    for (int i = 0; i < edges; ++i){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, nodes);
    for (int i = 0; i < nodes; ++i){
        if (visited[i]) continue;
        dfs(i,adj);
        connectedComponents++;
    }
    cout << "Number of connected components: " << connectedComponents << endl;
}