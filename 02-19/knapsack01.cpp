#include<bits/stdc++.h>
using namespace std;

void knapsack(vector<pair<int, int> > v,int w, int n){
	vector<vector<int> > T(n+1, vector<int> (w+1, 0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=w;j++){
			if(v[i].first<=j)
				T[i][j]=max((T[i-1][j]),(T[i-1][j-v[i].first]+v[i].second));
			else{
				T[i][j]=T[i-1][j];
			}
			cout<<T[i][j]<<"\t";
		}
		cout<<endl;
	}
	int i=n,j=w;
	int arr[n+1]={0};
	while(i>0&&j>0){
		if(T[i][j]!=T[i-1][j]){
			arr[i]=1;
			j-=v[i--].first;
		}
		else{
			i--;
		}
	}
	for(int i=1;i<n+1;i++){
		cout<<arr[i]<<endl;
	}
	
}

int main(){
	int n,w;
	cin>>n>>w;
	vector<pair<int, int> > v(n+1); //weight,benifit
	v[0]={0,0};
	for(int i=1;i<=n;i++){
		cin>>v[i].second>>v[i].first;
	}
	sort(v.begin(),v.end());
	knapsack(v,w,n);
}
/*
4 8
2 3
3 4
4 5
1 6
*/
