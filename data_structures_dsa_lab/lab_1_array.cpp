//program to perform insertion, deletion, traversing operation on array
#include<bits/stdc++.h>

using namespace std;
int arr[30]={6,5,7,4,8,4,9,1,2,11,99,55,33,22};
int size=14;
void insert(int v,int p){
	int x;
	for (int i=p;i<size;i++){
		x=arr[i];
		arr[i]=v;
		v=x;
	}
	cout<<"insertion successful"<<endl;
}

void del(int p){
	size--;
	for (int i=p;i<size;i++){
		arr[i]=arr[i+1];
	}
	cout<<"deletion successful"<<endl;
}

void trav(){
	cout<<"elements are"<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<endl;
	}
	
}

int main(){
	int x,val,pos;
	while(1){
	cout<<"press 1 to insert\npress 2 to delete\npress 3 to traverse";
	cin>>x;
	switch(x){
		case 1 : {
			cout<<"enter element you want to insert";
			cin>>val;
			cout<<"enter position";
			cin>>pos;
			insert(val,pos);
			break;
			}
		case 2 : {			
			cout<<"enter index to be deleted";
			cin>>pos;
			del(pos);
			break;
			}
		
		case 3 : {
			trav();
			break;
		}
		default : {
			cout<<"enter valid case";
			exit(0);
		}
	}
	}
	return(0);
}
