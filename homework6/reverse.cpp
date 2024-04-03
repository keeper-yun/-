
#include<iostream>
#include<stdlib.h>
using namespace std;

#define N 100

typedef struct{
	
	int a[N];
	int front;
	int rear;
	
}Qnode; 



typedef struct {
	
	int *base;
	int *top;
	int stacksize;
	
}Seqstack; 



void initstack(Seqstack &L){
	
	L.base = (int *)malloc(sizeof(int)*N);	
	L.top = L.base;
	L.stacksize = N;

}



int push(Seqstack &L,int x){
	
	if(L.top - L.base >= L.stacksize){
		return 0;	
	}
	
	*L.top = x;
	L.top++;
	
	return 1;
	
}



int pop(Seqstack &L){
	
	if(L.base==L.top)
		return -1;
	
	L.top--;
	int x = *L.top;
	
	return x;
}



void init(Qnode &Q){
	
	Q.front = Q.rear = 0;
	
}



int EnQueue(Qnode &Q,int x){
	
	if( (Q.rear+1)%N == Q.front)
		return 0;
	
	Q.a[Q.rear] = x;
	Q.rear = (Q.rear+1) % N;
	
	return 1;
}



int DeQueue(Qnode &Q,int &x){
	
	if(Q.front==Q.rear)
		return 0;
	
	x = Q.a[Q.front];
	Q.front = (Q.front+1) % N;
	
	return 1;
}



void reverseOdd(Qnode &Q) {
	
	Seqstack L;
	initstack(L);
	Qnode B;
	init(B);
	
	int len = Q.rear-Q.front;
	int x;
	int judge=0;
	
	for(int i=0;i<len;i++){
		
		DeQueue(Q,x);
		
		if(x%2==1){
			push(L,x);	
		}
		
		EnQueue(B,x);
		
	}
	

	
	while(B.front!=B.rear){
		
		DeQueue(B,x);
		
		if(x%2==0){
			cout<<x<<" ";	
		}else if(x%2==1){
			cout<<pop(L)<<" ";
		}
		
	}
		
	
	cout<<endl;
}



int main(){

 int len,num;

    Qnode A;
	init(A);
	
    cin >> len;

    for (int i = 0; i < len; i++) {

        cin >> num;
        EnQueue(A,num);

    }

    reverseOdd(A);

	return 0;
}




