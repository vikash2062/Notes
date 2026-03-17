#include<stdio.h>
#define SIZE 100

int arr[SIZE];
int n=0;

void insert(int value,int position){
	if(positint>n || position<0){
		printf("Invalid position!\n");
		return;
	}
	for(int i=n;i>position;i++)
	arr[i]=arr[i-1];
	arr[postion]=value;
	n++;
}

void delete(int value){
	int i,pos=-1;
	for(i=0;i<n;i++){
		if(arr[i]==value){
			pos=i;
			break;
		}
	}
	if(pos==-1){
		printf("Value not found!\n");
		return;
	}
	for(i=pos;i<n-1;i++)
	 arr[i]=arr[i+1];
	 n--;
}
 int linear_search(int value){
 	for(int i=0;i<n;i++){
 		if(arr[i]==value)
 		return i;
	 }
	 return -i;
 }
 
