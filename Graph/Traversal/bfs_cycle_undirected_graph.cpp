#include<bits/stdc++.h>
using namespace std;

bool visited[100000];
unordered_map<int, int> parent;
bool bfs(int s, vector<int> adj[])
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int p = -1;
    parent[s] = -1;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        for (int i = 0; i < adj[p].size(); i++)
        {
            if (adj[p][i] == parent[p])
                continue;
            else if (visited[adj[p][i]])
                return true;
            q.push(adj[p][i]);
            visited[adj[p][i]] = true;
            parent[adj[p][i]] = p;
        }
    }
    return false;
}
bool isCycle(int v, vector<int> adj[])
{
    memset(visited, false, v);
    bool ans = false;
    for (int i = 0; i < v; i++){
        if (!visited[i])
            ans = bfs(i, adj);
        if (ans)
            return true;
    }
    return false;
}

int main(){
    
}