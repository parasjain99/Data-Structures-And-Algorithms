#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > G;
vector<int> d(100, 100000001), vis(100, 0), q, wt(100);
int n,e,w,s,x1,x2;
void bell(){
    d[s]=0;
    pair<int,int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<e;j++){
            temp = G[j];
            if(d[temp.second]>(d[temp.first]+wt[j])) 
                d[temp.second] = d[temp.first]+wt[j];
        }
    }
    for(int i=0;i<e;i++){
        temp = G[i];
        if (d[temp.second] > (d[temp.first] + wt[i])){
            cout<<"Negative Cycle";
            return;
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
        G.push_back({x1,x2});
        wt[i]=w;
    }
    bell();
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
1 -1
2 2
3 -2
4 1
*/