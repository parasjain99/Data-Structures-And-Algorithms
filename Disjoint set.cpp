/* You are given number of nodes, N, and number of edges, M, of a undirected connected graph. After adding each edge, print the size of all the connected components (in increasing order).

Input:
First line contains two integers, N and M, number of nodes and number of edges.
Next M lines contains two integers each, X and Y, denoting that there is an edge between X and Y.

Output:
For each edge, print the size of all the connected components (in increasing order) after adding that edge. */


#include<bits/stdc++.h>
using namespace std;

void connect(vector<int> &set,pair<int,int> edge){
    int root1,root2;
    for(root1=edge.first ; set[root1]>0;){
        root1 = set[root1];
    }
    for(root2=edge.second ; set[root2]>0;){
        root2 = set[root2];
    }
    if(set[root1]>set[root2]){
        set[root2]+=set[root1];
        set[root1]=root2;
        
    }
    else{
        set[root1]+=set[root2];
        set[root2]=root1;
    }
}

int main(){
    int n,m,x,y;
    cin>>n>>m;
    vector<pair<int,int>> edge;
    vector<int> set(n+1,-1),order; //start from index 1
    for(int i=0;i<m;i++){
        order.clear();
        cin>>x>>y;
        edge.push_back({x,y});
        connect(set,edge[i]);
        cout<<endl;
        for(int j=1;j<set.size();j++){
            if(set[j]<0){
                order.push_back((set[j]*-1));
            }
        }
        sort(order.begin(),order.end());
        for(int j:order){
            cout<<j<<" ";
        }
    }
}