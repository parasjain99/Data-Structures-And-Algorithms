#include<bits/stdc++.h>
using namespace std;

int go(string &s,int j,int i=0){
	if(i==j) return 1;
	if(i>j) return 0;
	if(s[i]==s[j]) return (go(s,j-1,i+1)+2);
	else return max(go(s,j-1,i),go(s,j,i+1));
}

int main(){
	string s;
	cin>>s;
	int n=s.length();
	cout<<go(s,n-1);
}
