#include<bits/stdc++.h>
using namespace std;

int part(vector<int> &a,int l,int h){
	int pivot, temp, n,i,j;
	
	n = rand();
	temp = l + n%(h-l);
	pivot = a[temp];
	a[temp] = a[l];
	a[l] = pivot;
	i = l;
	j = h;
	while(i<j){
		do{
			i++;
		}while(a[i]<pivot);
		
		do{
			j--;
		}while(a[j]>pivot);
		
		if(i<j){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;	
		}
	}
	a[l] = a[j];
	a[j] = pivot;
	return j;
}

void QSort(vector<int> &a, int l=-1, int h=-1){
	if(l==-1&&h==-1){
		l=0;
		h=a.size();
//		cout<<"inside if l="<<l<<" h="<<h<<endl;
	}
	if(l<h){
		int	j=part(a,l,h);
		QSort(a,l,j);
		QSort(a,j+1,h);
	}
}


int main(){
	int n,x;
	vector<int> a;
	cout<<"Number of elements: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		a.push_back(x);
	}
	QSort(a);
	for(int i=0;i<n;i++){
		cout<<endl<<a[i];
	}
}
