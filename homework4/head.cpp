//作业第三题


#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct LNode{

    int data;
    struct LNode *next;

}LNode,*local;



void init(local &L){
    L = (local)malloc(sizeof(LNode));
    L->data = 0;
    L->next=NULL;
}



//插入 
void insert(local &L,int a,int x){
    local p = L;
    for(int count = 0;count<a-1;count++){
        p=p->next;
    }

    local s = (local)malloc(sizeof(LNode));
    s->data = x;
    s->next=p->next;
    p->next = s;

}



int merge(local &L1,local &L2,local &L3){
    local p = L1->next;
    local p2 = L2;  ///   local p2 = L2->next;
    local p3 = L3;
    int i = 0;

    while(p&&p2){
        if(i%2 == 0){
            p3->next=p;
            p=p->next;
        }else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
        i++;
    }
    if(p){
        p3->next=p;
    }else{
        p3->next=p2;
    }
    return 1;
}



//重新排序 
int reorder(local &L,int a){
    local p = L->next;
    local p2=NULL;
    local p3=L;
    int count = 0;


	for(int i=0;i<a;i++){
		p=p->next;
	} 
	
	p2 = p->next;

    p = L->next;
    
	for(int i=0;i<a;i++){
		p=p->next;
	} 
	
    p->next = NULL;

    merge(L,p2,p3);///  merge(p,p2,p3);
    return 1;
}



void write(local &L,int n){
    local p = L->next;
    for(int i = 0;i<n;i++){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;

}



int main(){
    int x,n,a;
    local A;
    init(A);

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        insert(A,i+1,x);
    }

    cin>>a;

    reorder(A,a);

    write(A,n);

    return 0;
}
