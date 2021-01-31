#include<bits/stdc++.h>
using namespace std;

bool visited[100000];
bool dfs(int s, int parent, vector<int> adj[])
{
    if (visited[s])
        return true;
    visited[s] = true;
    for (int i = 0; i < adj[s].size(); i++)
    {
        bool ans = false;
        if (adj[s][i] != parent)
            ans = dfs(adj[s][i], s, adj);
        if (ans)
            return true;
    }
    return false;
}

bool isCycle(int v, vector<int> adj[])
{
    memset(visited, false, v);
    bool ans = false;
    for (int i = 0; i < v; i++){
        if(!visited[i]) ans = dfs(i,-1,adj);
        if (ans)
            return true;
    }
    return false;
}

int main(){
    
}