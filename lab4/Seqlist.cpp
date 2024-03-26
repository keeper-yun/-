
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
		cout<<"栈顶元素是:"<<x<<endl;
	}else{
		cout<<"栈顶为空，没有元素!"<<endl;
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
		cout<<"栈顶为空，没有元素!"<<endl;
		return true;
	}
	
	int x = *L.top;
	L.top--;
	cout << "删除的栈顶元素是:"<<x<<endl;
	return true;
}



int main(){
	
	SeqStack A;
	
	init(A);//初始化 
	
	push(A,1);//插入元素 
	
	getelem(A);//获取栈顶元素 
	
	pop(A);//删除栈顶元素 
	
	getelem(A);
	
	return 0;
}
