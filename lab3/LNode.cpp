#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct LNode{
	
	int data;
	struct LNode *next;
	
}LNode,*local;



void init(local &head){
	head = (local)malloc(sizeof(LNode));
	head->next=NULL;
}



void length(local head){
	int count = 0;
	local p = head->next;
	while(p){
		count++;
		p=p->next;
	}
	cout<<"��������:"<<count;
}



void clear(local &head){
	head->next=NULL;
	local p=head;
}



void insert(local &head,int a,int x){
	local p = head;
	for(int count = 0;count<a-1;count++){
		p=p->next;
	}
	
	local s = (local)malloc(sizeof(LNode));
	s->data = x;
	s->next=p->next;
	p->next = s;
	
}



void getlocal(local &head,int i){
	local p = head->next;
	int count=0;
	int x;
	while(p&&count<i-1){
		p=p->next;
		count++;
	}
	x=p->data;
	cout<<"��"<<i<<"��λ�õ�Ԫ����:"<<x;
	cout<<endl;
}



void remove(local &head,int i){
		local p = head;
		int x;
	for(int count = 0;count<i-1;count++){
		p=p->next;
	}
	
	local s = (local)malloc(sizeof(LNode));
	s=p->next;
	x=s->data;
	p->next=s->next;
	free(s);
	cout<<"��"<<i<<"��λ�ñ�ɾ����Ԫ����:"<<x;
	cout<<endl;
}



void merge(local &A,local &B,local &C){
	local p1=A->next;
	local p2=B->next;
	local p3=C;
	
	while(p1&&p2){	
		if(p1->data == p2->data){
			p3->next=p1;
			p1=p1->next;
			p2=p2->next;	
		}else if(p1->data < p2->data){
			p3->next=p1;
			p1=p1->next;
		}else{
			p3->next=p2;
			p2=p2->next;
		}
		p3=p3->next;
	}
	
	if(p1){
		p3->next=p1;
	}else{
		p3->next=p2;
	}
	
}

void write(local head){
	local p=head->next;
	int count=0;
	while(p){
		int num=p->data;
		cout<<num<<" ";
		p=p->next;
		count++;
	}
	if(p==NULL&&count==0){
		cout<<"����һ���ձ�!";;
	}
		cout<<endl;
}

int main(){
	local head;
	init(head);
	
	for(int i=0;i<10;i++)
		insert(head,i+1,i+1);
	
	length(head);
	cout<<endl;
	
	getlocal(head,2);
	write(head);
	
	remove(head,3);
	write(head);
	
	clear(head);
	write(head);


	local A,B,C;
	init(A);
	init(B);
	init(C);
	
	for(int i=0;i<10;i++)
		insert(A,i+1,i*2);
	cout<<"�ϲ�ǰA��:";
	write(A);
	
	for(int i=0;i<10;i++)
		insert(B,i+1,i+1);
	cout<<"�ϲ�ǰB��:";
	write(B);
	
	merge(A,B,C); 
	cout<<"�ϲ����:";
	write(C);
	
	cout<<endl;
	return 0;
}


