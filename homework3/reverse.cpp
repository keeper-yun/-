#include<iostream>
#include<malloc.h>

using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*local;



void init(local &L){
	L=(local)malloc(sizeof(LNode));
	L->next=NULL;
}



void insert(local &L,int a,int x){
	local p=L;
	for(int i=0;i<a-1;i++){
		p=p->next;
	}
	
	local s=(local)malloc(sizeof(LNode));
	s->data=x;
	s->next=p->next;
	p->next=s;
	
}



void reverse(local &L){
	local p=L->next;
	L->next=NULL;
	while(p){
		local s=p;
		p=p->next;
		s->next=L->next;
		L->next=s;
	}
} 



void write(local &L){
	local p=L->next;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}




int main(){
	
	local A;
	init(A);
		
	int x,num;	
	cin>>x;
	
	for(int i=0;i<x;i++){	//插入链表中的值
		cin>>num;
		insert(A,i+1,num);
	}
	
	
	reverse(A);				//倒序 
	write(A); 				//4，3，2，1 
	

	
	return 0;
}
