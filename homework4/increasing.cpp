//作业第二题
 

#include<iostream>
#include<malloc.h>

using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*local;



void init(local &L){
	L = (local)malloc(sizeof(LNode));
	L->next = NULL;	
}



void insert(local &L,int a,int x){
	local p = L;
	
	for(int i=0;i<a-1;i++){
		p = p->next;	
	}
	
	local s = (local)malloc(sizeof(LNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
	
}



bool sort(local &L){
	if(L->next == NULL || L->next->next ==NULL){
		return false;
	}
	
	local p = L->next;

	while(p->next&&p){
		local p2 = L->next;
		while(p2->next){
			if(p2->data > p2->next->data){
				int temp = p2->data;
				p2->data = p2->next->data;
				p2->next->data = temp;
			}	
			p2 = p2->next;
		}
		p = p->next;
	}
	return true;
}



void write(local &L,int n){
	local p = L->next;
	for(int i = 0;i<n;i++){
		cout<<p->data<<" ";
		local temp = p->next;
		free(p);
		p = temp;
	}
	cout<<endl;
	free(L);
}



int main(){
	local A;
	int n,x;
	
	init(A);
	
	cin>>n;
	
//	if(n<=0){
//		cout<<"error"<<endl;
//	}
	
	for(int i=0;i<n;i++){
		cin>>x; 
		insert(A,i+1,x);
	}
	
	sort(A);
	
	write(A,n);
	
	return 0;
}
