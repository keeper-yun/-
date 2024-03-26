
#include<iostream>
#include<malloc.h>
using namespace std;

#define N 100
#define add 10

typedef struct {
	int *base;
	int *top;
	int stacksize;
}SeqStack; 



void init(SeqStack &L){
	L.base = (int *)malloc(sizeof(int)*N);	
	L.top = L.base;
	L.stacksize = N;
}



bool empty(SeqStack &L){
	
	if(L.base == L.top){
		return true;
	} 
	return false;
}


void getelem(SeqStack &L){
	if(!empty(L)){
		int x = *L.top;
		cout<<"ջ��Ԫ����:"<<x<<endl;
	}else{
		cout<<"ջ��Ϊ�գ�û��Ԫ��!"<<endl;
	}
	
}



int push(SeqStack &L,int x){
	
	if(L.top-L.base > N){
		L.base = (int *)realloc(L.base,(sizeof(int)*(L.stacksize+add)));
		L.top = L.base + L.stacksize;
		L.stacksize +=add;
	}
	
	L.top++;
	*L.top = x;
}



bool pop(SeqStack &L){
	
	if(empty(L)){
		cout<<"ջ��Ϊ�գ�û��Ԫ��!"<<endl;
		return true;
	}
	
	int x = *L.top;
	L.top--;
	cout << "ɾ����ջ��Ԫ����:"<<x<<endl;
	return true;
}



int main(){
	
	SeqStack A;
	
	init(A);//��ʼ�� 
	
	push(A,1);//����Ԫ�� 
	
	getelem(A);//��ȡջ��Ԫ�� 
	
	pop(A);//ɾ��ջ��Ԫ�� 
	
	getelem(A);
	
	return 0;
}
