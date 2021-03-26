#include<bits/stdc++.h>
using namespace std;
int g[100][100]={0};
vector<int> d(100, 100000001), vis(100, 0), q;
int n,e,w,s,x1,x2;
bool mycomp(int a, int b){ return d[a]>d[b]; }
void dijkstra(){
    int temp;
    d[s]=0;
    q.push_back(s);
    vis[s]=1;
    while(!q.empty()){
        sort(q.begin(), q.end(), mycomp);
        temp = q[q.size() - 1];
        q.pop_back();
        for(int i=0;i<n;i++){
			if(g[temp][i]!=0){
                if (d[i] > (g[temp][i] + d[temp]))
                    d[i] = g[temp][i] + d[temp];
                if(vis[i]==0){
                    q.push_back(i);
                    vis[i]=1;
                } 
			}
		}		
    }
    cout<<"Minimum distances are: \n";
    for(int i=0;i<n;i++){
        cout<<i<<" dist="<<d[i]<<endl;
    }
}

int main(){
    cin>>n>>e>>s;
    for(int i=0;i<e;i++){
        cin>>w>>x1>>x2;
        g[x1][x2]=w;
        g[x2][x1]=w;
    }
    dijkstra();
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
