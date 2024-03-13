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



bool insert(local &L,int a,int x){
	local p=L;
	if(a<1||p==NULL)
		return false;
	for(int i=0;i<a-1;i++){
		p=p->next;
		if(p==NULL)
			return false;
	}
	
	local s=(local)malloc(sizeof(LNode));
	s->data=x;
	s->next=p->next;
	p->next=s;
	return true;
}



bool reverse(local &L){
	local p=L->next;
	L->next=NULL;
	
	if(p==NULL||p->next==NULL)
		return false;
		
	while(p){
		local s=p;
		p=p->next;
		s->next=L->next;
		L->next=s;
	}
	return true;
} 



void write(local L){
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
	//cout<<"������Ҫ����Ԫ�صĸ���:"<<endl;	
	cin>>x;
	
	for(int i=0;i<x;i++){	//���������е�ֵ
		cin>>num;
		insert(A,i+1,num);
	}
	
	
	reverse(A);				//���� 
	write(A); 				//4��3��2��1 
	

	
	return 0;
}
