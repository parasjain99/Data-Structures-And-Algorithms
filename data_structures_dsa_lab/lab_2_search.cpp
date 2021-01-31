#include<iostream>

using namespace std;

int a[100]={2,4,5,8,11,25,34,78,81,90,95};

void linearSearch(int x, int n){
	for (int i=0;i<n;i++){
		if(a[i]==x){
		cout<<"Element Found\n";
		return;
		}
	}
		cout<<"Element not found\n";
}

void binarySearch(int x, int n){
	int l=0,h=n,mid=(l+h)/2;
	while(l<=h){
		mid=(l+h)/2;
		if(a[mid]<x){
			l=mid+1;
		}
		else if(a[mid]>x)
			h=mid-1;
		else if(a[mid]==x){
			cout<<"Element Found\n";
			return;
		}
	}
	cout<<"Element not found\n";
}


void binRec(int x, int h, int l=0){
	
	int mid=(l+h)/2;
	if(l<=h){	
		if(a[mid]==x){
			cout<<"element found\n";
			return;
		}
		else if(x<a[mid]){
			binRec(x,mid-1);
			return;
		}
		else if(x>a[mid]){
			binRec(x,h,mid+1);
			return;
		}
	}
		else{
	cout<<"Element not found\n";
	return;
	}
}



main(){
	
	int s,x,n=12;
	cout<<"Choose the options below\n";
	cout<<"Press 1 to display elements\n";
	cout<<"Press 2 to perform linear search\n";
	cout<<"Press 3 to perform binary search by iterative method\n";
	cout<<"Press 4 to perform binary search be recursive method\n";
	cout<<"Press 5 to insert elements";
	while(1){
		cin>>s;
		switch(s){
			case 1 : {
					cout<<endl;
					for(int i=0;i<n;i++)
					cout<<a[i]<<endl;
					break;
			}
			case 2 : {
					cout<<"enter element you want to search";
					cin>>x;
					linearSearch(x,n);
					break;
			}
			case 3 : {
					cout<<"enter element you want to search";
					cin>>x;
					binarySearch(x,n);
					break;
			}
			case 4 : {
					cout<<"enter element you want to search";
					cin>>x;
					binRec(x,n);
					break;
			}
			case 5 : {
				cout<<"enter size of the array";
				cin>>n;
				for(int i=0;i<n;i++){
					cin>>a[i];
				}
				cout<<"success"<<endl;
				break;
			}
			default : {
					cout<<"enter valid choice";
					exit(0);
			}
		}
	
	}
}



