#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


//int arr[100]={1,4,5,7,3,9,56,32,45,98};
int *arr;
//int size=10;

void BubbleSort(int n){
	int temp, swap=1;
	for(int pass=n-1;(pass>=0)&&swap;pass--){
		swap=0;
		for(int i=0;i<=pass-1;i++){
			if(arr[i]>arr[i+1])
			{
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
				swap=1;
			}
		}
	}
}
void SelectionSort(int n){
	int min=0,temp;
	for(int i=0;i<n;i++){
		min=i;
		for(int j=i+1;j<n;j++){
			if(arr[min]>arr[j]){
				min=j;
			}
		}
		//swap
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}

void InsertionSort(int n){
		int temp,i,j;
	for (i=1;i<n;i++){
			temp=arr[i];
		for(j=i;(j>0)&&temp<arr[j-1];j--)
			{
				arr[j]=arr[j-1];
			}
			arr[j]=temp;
	}
}

int main(){
	int s,n=0;
	textcolor(4);
	while(1){
	cprintf("Press 1 to enter values\nPress 2 print the values\n");
	cprintf("Press 3 to perform BubbleSort\nPress 4 to perform SelectionSort\nPress 5 to perform InsertionSort\n");
	scanf("%d",&s);
	switch(s){
		case 1 : {
			printf("enter number of values you want to insert\n");
			scanf("%d",&n);
			arr=(int*) malloc(n * sizeof(int));
			for(int i=0;i<n;i++){
				scanf("%d",&arr[i]);
			}
			break;
		}
		case 2 : {
			if(n){
			for(int i=0;i<n;i++)
			printf("%d\n",arr[i]);
			break;
			}
			else
			printf("first insert values\n");
			break;
		}
		case 3 : {
			BubbleSort(n);
			break;
		}
		case 4 : {
			SelectionSort(n);
			break;
		}
		case 5 : {
			InsertionSort(n);
			break;
		}
		default : {
			printf("enter valid choice");
			exit(0);
		}
	}
}
}
