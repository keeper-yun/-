//作业第一题 


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
		p=p->next;
	}
	
	local s = (local)malloc(sizeof(LNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
	
}



void getelem(local &L,int x){
	int count = 0;
	local p = L->next;
	while(p){
		count++;
		p=p->next;
	}
	
	if(x <= 0 || x > count ){
		cout<<"Not Found"; 
	}else{
		p = L->next;
		for(int i=0;i<count-x;i++){
			p=p->next;
		}
		cout<<p->data;
	}
}



int main(){
	local A;
	init(A);
	
	int x,a;
	cin>>x;
	
	for(int i=0;i<100;i++){
		cin>>a;
		insert(A,i+1,a);
		if(cin.peek() == '\n')
			break;
	}
	
	getelem(A,x);
	
	return 0;
}
