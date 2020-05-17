#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2,sub;
    cin>>s1>>s2;
    int l1=s1.length(), l2=s2.length();
	map<int,map<int,int> > dp;
    for(int i=0;i<l1;i++){
        for(int j=0;j<l2;j++){
            if(s1[i]==s2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } 
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<dp[l1-1][l2-1];
    int x=l1-1,y=l2-1;
    while(x!=-1&&y!=-1){
        if(dp[x][y]==dp[x-1][y]) x--;
        else if(dp[x][y]==dp[x][y-1]) y--;
        else{
        	sub.push_back(s1[x]);
        	x--;
        	y--;
        }
    }
    reverse(sub.begin(),sub.end());
    cout<<endl<<sub;
}

// acbcf
// abcdaf
