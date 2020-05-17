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
        temp = G[j];
        if (d[temp.second] > (d[temp.first] + wt[j])){
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
5 8 0
-1 0 1
4 0 2
3 1 2
2 1 3
2 1 4
5 3 2
1 3 1
-3 4 3

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
