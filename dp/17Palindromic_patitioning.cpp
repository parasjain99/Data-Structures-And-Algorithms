#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isPalindrome(string &s,int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s, int i, int j,vector<vector<int>>&dp){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>=j) return dp[i][j] = 0;
        if(isPalindrome(s,i,j)) return dp[i][j] = 0;
        int mn = INT_MAX;
        for(int k=i;k<j;k++){
            // int temp = 1 + solve(s,i,k,dp) + solve(s,k+1,j,dp);
            if(dp[i][k]==-1) solve(s,i,k,dp);
            if(dp[k+1][j]==-1) solve(s,k+1,j,dp);
            int temp = 1 + dp[i][k] + dp[k+1][j];
            mn = min(temp,mn);
        }
        return dp[i][j] = mn;
    }
    int palindromicPartition(string &str){
        int n = str.length();
        vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
        return solve(str,0,n-1,dp);
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  