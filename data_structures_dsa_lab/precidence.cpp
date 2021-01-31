#include <bits/stdc++.h>
using namespace std;
bool prec(char c){
    if(c=='^') return 3;
    else if(c=='*'||c=='/') return 2;
    else if(c=='+'||c=='-') return 1;
    else return 0;
    
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    stack<char> stk;
	    for(int i=0;i<s.length();i++){
	        if((s[i]>'!'&&s[i]<='/')||s[i]=='^'){
	            if(s[i]=='(') stk.push('(');
	            else if(s[i]==')'){
	                while(stk.top()!='('){
	                    char ch = stk.top();
	                    stk.pop();
	                    cout<<ch;
	                }
	                if(stk.top()=='(')
	                    stk.pop();
	            }
	            else if(stk.empty()){
	                stk.push(s[i]);
	            }
	            else if(prec(stk.top())>=prec(s[i])){
	                cout<<stk.top();
	                stk.pop();
	                stk.push(s[i]);
	            }
	            else{
	                stk.push(s[i]);
	            }
	        }
	        else cout<<s[i];
	    }
	    while(!stk.empty()){
	        cout<<stk.top();
	        stk.pop();
	    }
	    cout<<endl;
	}
	return 0;
}