//Segment tree to find maximum 0 based indexing
#include<bits/stdc++.h>
using namespace std;
int a[100005], seg[4*100005];
void build(int ind,int low, int high){
    if(low==high){
        seg[ind] = a[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
}

void update(int node, int low, int high, int idx, int val){
    if(low==high){ // Leaf Node
        a[idx] = val;
        seg[node] = val;
    }
    else{
        int mid = (low+high)/2;
        if(low<=idx and idx<=mid) update(2*node+1,low,mid,idx,val); //If idx is in the left child  
        else update(2*node+2,mid+1,high,idx,val); // If idx is in the right child
        seg[node] = max(seg[2*node+1],seg[2*node+2]);
    } 
}

int query(int ind, int low, int high, int l, int r){
    if(low>r or high<l) return INT_MIN;
    if(low>=l and high<=r) return seg[ind];
    int mid = (low+high)/2;
    int left = query(2*ind+1,low,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);
    return max(left,right);
}

int main(){
    int n,q;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    build(0,0,n-1);
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r);
    }
}