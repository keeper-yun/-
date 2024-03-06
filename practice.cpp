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




//Seqlist类型
#include <iostream>
#include <malloc.h>
using namespace std;

#define List_Length 10
#define Add 5

typedef double ElemType;

typedef struct Seqlist{
	ElemType *elem;
	int length;
	int listsize;
}SeqList;


bool init(Seqlist &L){
	L.elem=(ElemType *)malloc(List_Length*sizeof(ElemType));
	L.length=0;
	L.listsize=List_Length;
	return true;
}
 
 int insert(Seqlist &L,int i,ElemType x){
 	//返回1 表示成功 0 表示失败 
 	if (i<1 || i>L.length+1)
 		return 0;
 	if (L.length>=L.listsize){
 		L.elem=(ElemType *)realloc(L.elem,(L.listsize+Add)*sizeof(ElemType));
	 	L.listsize+=Add;
	 }	
 		
 	for (int j=L.length-1;j>=i-1;j--)
	 	L.elem[j+1]=L.elem[j] ;
	L.elem[i-1]=x;
	L.length++;
	return 1;	 	
 }
 
 int remove(Seqlist &L,int i,ElemType &x){
 	//返回1 表示成功 0 表示失败 
 	if (i<1 || i>L.length)
 		return 0;
	x = L.elem[i-1];
	for (int j=i;j<=L.length-1;j++)
 		L.elem[j-1]=L.elem[j];
 	L.length--;	
 	return 1;
 }
 
 
void traverse(Seqlist &L){
	for (int i=0;i<L.length;i++)
		cout<<L.elem[i]<<" ";
}
int main(){
	Seqlist A;	
	ElemType x;
	init(A);
	for (int i=0;i<10;i++)
		insert(A,i+1,i+1);
	//remove(A,3,x);
	traverse(A);
	cout<<endl;
	//cout<<endl<<x;
	system("pause");
	return 0;
}

