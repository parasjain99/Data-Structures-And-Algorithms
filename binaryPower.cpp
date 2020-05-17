//program for binary exponentiation
#include<bits/stdc++.h>
using namespace std;
int binaryExpo(int x,int p){
	int result=1;
	while(p){
		if(p%2==1)
			result=result*x;
			
		x=x*x;
		p=p/2;
	}
	return(result);
}


int main(){
	int num,pow,ans;
	cout<<"number then power";
	cin>>num>>pow;
	ans=binaryExpo(num,pow);
	cout<<num<<"^"<<pow<<"="<<ans;
	
	return(0);
}
