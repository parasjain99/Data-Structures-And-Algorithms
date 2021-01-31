#include<bits/stdc++.h>
using namespace std;
vector<int> check(string s, string x){
    vector<int> v;
    int flag;
    for(int i=0;i<s.length();i++){
        if(s[i]==x[0]){
            flag=1;
            for(int j=0;j<x.length();j++){
                if(s[i+j]!=x[j]){
                    flag = 0;
                    break;
                }
            }
            if(flag==1)
                v.push_back(i);
        }
    }
    return v;
}
int main(){
    vector<int> v;
    string s,x;
    cin>>s;
    cin>>x;
//    s = "abcdef abcabcabcdfeabc";
//    x = "abc";
    v = check(s,x);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}
