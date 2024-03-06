//#include <stdio.h>
//
//int main() {
//    printf("Hello, World!\n");
//    return 0;
//}


//#include<iostream>
//using namespace std;
//
//typedef struct SeqList{
//	int a[100];
//	int length;
//}SeqList;
//
//void init(SeqList &L,int a[],int len){
//	L.length=len;
//	for(int i=0;i<L.length;i++){
//		L.a[i]=a[i]; 
//	}
//}
//
//bool insert(SeqList &L,int a,int num){
//	if(a<0 || a>L.length+1 || L.length>=100)
//        return false;
//    if(L.length>=100)
//        return false;
//	for(int i=L.length-1;i>a-1;i--){
//		L.a[i+1]=L.a[i];
//	}
//	L.a[a]=num;
//	L.length++;
//	return true;
//}
//
//bool remove(SeqList &L,int seat,int &rm){
//	if(seat<1 || seat>L.length)
//        return false;
//	rm = L.a[seat-1];
//	for(int i=seat-1;i<L.length;i++){
//		L.a[i]=L.a[i+1];
//	}
//	L.length--;
//	return true;
//}
//
//void write(SeqList &L){
//	for(int i=0;i<L.length;i++){
//		cout<<L.a[i]<<" ";
//	}
//	delete[]L.a;
//	cout<<endl;
//}
//
//int main(void){
//	SeqList A;
//	int x=0;
//	int a[5]={1,2,3,4,5};
//	init(A,a,5);
//	insert(A,5,6);//在第几个数后面插入几 
//	remove(A,1,x);//删掉第几个数,删掉的数是多少 
//	write(A);
// 
//	cout<<x<<endl;
//
//	system("pause");
//	return 0;
//}




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
//	return true;
}

 int insert(SeqList &L,int i,int x){ 
 	if (i<1 || i>L.length+1)
 		return 0;
 	if (L.length>=L.listlen){
 		L.a=(int *)realloc(L.a,(L.listlen+Add)*sizeof(int));
	 	L.listlen+=Add;
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

