#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
string s1,s2,sub;
map<int,map<int,int> > dp;
int go(int l1,int l2){
    if(l1<0||l2<0) return 0;
    if(dp[l1][l2]>0) return dp[l1][l2];
    if(s1[l1]==s2[l2]) dp[l1][l2] = max(1+go(l1-1,l2-1),max(go(l1-1,l2),go(l1,l2-1)));
    else dp[l1][l2] = max(go(l1-1,l2),go(l1,l2-1));
    return dp[l1][l2]; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>s1>>s2;
    int l1=s1.length(), l2=s2.length();
    cout<<go(l1-1,l2-1);
}