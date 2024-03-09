#include<iostream>
#include<malloc.h>
using namespace std;

#define N 10
#define Add 5

typedef struct SeqList{
	int *a;
	int length;
	int listlen;
	
}SeqList;

void init(SeqList &L){
	L.a=(int *)malloc(N*sizeof(int));
	L.length=0;
	L.listlen=N;
}

 int insert(SeqList &L,int i,int x){ 
 	if (i<1 || i>L.length+1)
 		return 0;
 	if (L.length>=L.listlen){
 		L.listlen+=Add;
 		L.a=(int *)realloc(L.a,(L.listlen)*sizeof(int));

	 }	
 		
 	for (int j=L.length-1;j>=i-1;j--)
	 	L.a[j+1]=L.a[j] ;
	L.a[i-1]=x;
	L.length++;
	return 1;	 	
 }

void write(SeqList &L){
	for(int i=0;i<L.length;i++){
		cout<<L.a[i]<<" ";
	}
}

int main(void){
	SeqList A;
	init(A);
	for(int i=0;i<15;i++){
		insert(A,i+1,i+1);
	}
	write(A); 
	cout<<endl;
	free(A.a);
	
	return 0;
}



