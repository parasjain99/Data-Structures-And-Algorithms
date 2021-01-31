#include <bits/stdc++.h>
using namespace std;

bool visited[100000];
int level[100000];     //To determine the level of each node
void bfs(int s, vector<vector<int>> &adj){
    queue<int> q;
    q.push(s);
    level[s] = 0; //Setting the level of the source node as 0
    visited[s] = true;
    while (!q.empty()){
        int p = q.front();
        q.pop();
        for (int i = 0; i < adj[p].size(); i++){
            if (visited[adj[p][i]]) continue;
            //Setting the level of each node with an increment in the level of parent node
            level[adj[p][i]] = level[p] + 1;
            q.push(adj[p][i]);
            visited[adj[p][i]] = true;
            
        }
    }
}

int main(){
    int nodes, edges, x, y;
    cin >> nodes;
    cin >> edges;
    vector<vector<int>> adj(nodes);
    for (int i = 0; i < edges; ++i){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, nodes);
    memset(level, 0, nodes);
    bfs(0,adj);
}

