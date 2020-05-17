#include<bits/stdc++.h>
using namespace std;

vector<int> match(string s, string x){
	vector<int> v;
	int xl = x.length(), sl = s.length();
	int arr[xl];
	arr[0] = -1;
	for(int i=1,j=-1;i<xl;i++){
		
		if(x[i]==x[j+1])
			j++;
		
		else if(x[i]==x[0])
			j = 0;
		
		else
			j = -1;
		
		arr[i] = j;
			
	}
	
	for(int i=0,j=-1;i<sl;i++){
		
		if(s[i]==x[j+1]){
			j++;
			if((j+1) == xl){
				j=-1;
				v.push_back(i-xl+1);
				if(i>0)
				i--;
			}
			
		}
		
		else if(j>-1){
			j = arr[j];
			if(i>0)
				i--;
		}

	}
	
	return v;
}

int main(){
	vector<int> v;
	string s,x;
	cout<<"Enter String: ";
	cin>>s;
	cout<<"Enter pattern: ";
	cin>>x;
//	s = "abcdadadbcaba";
//	x = "dad";
	v = match(s, x);
	if(v.size()<0){
		cout<<"Not found";
	}
	else{
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<endl;
		}
	}
	
}
