#include <bits/stdc++.h>
using namespace std;
int t,n;
bool ans = false;
vector<int> v;
map<int,int> c,d1,d2;
void go(){
    if(v.size()==n){
        cout<<"[";
        for(int i=0;i<n;i++){
            cout<<v[i]+1<<" ";
        }
        cout<<"] ";
        ans=true;
        return;
    }
    int col = v.size();
    for(int i=0;i<n;i++){
        if((c.find(i)==c.end() || c[i]==0)&&((d1.find(col-i)==d1.end() || d1[col-i]==0))&&(d2.find(i+col)==d2.end() || d2[i+col]==0)){
            c[i]=1;
            d1[col-i]=1;
            d2[i+col]=1;
            v.push_back(i);
            go();
            v.pop_back();
            c[i]=0;
            d1[col-i]=0;
            d2[i+col]=0;
        }
        
    }
}
int main() {
    cin>>t;
	while(t--){
	    cin>>n;
	    ans = false;
        go();
        if(ans==false) cout<<-1;
        cout<<endl;
	}
	return 0;
}