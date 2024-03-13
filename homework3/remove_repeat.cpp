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



bool remove_repeat(local &L){
	local p=L->next;
	
	if(p==NULL)
		return false;
		
	while(p){
		local a=p;
		while(a->next!=NULL){
			if(p->data == a->next->data){
				local tem =a->next;		
				a->next=a->next->next;
				free(tem);
			}else{
				a=a->next;
			}
		}
		p=p->next;
	}
	return true;
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
	
	int count;
	cin>>count;
	
	for(int i=0;i<count;i++){
		int x;
		cin>>x;
		insert(A,i+1,x);
	}	
	
	remove_repeat(A);
	write(A);
	
	return 0;
}
