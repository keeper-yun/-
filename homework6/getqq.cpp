
#include<iostream>
#include<string>
using namespace std;

#define N 100

typedef struct{
	
	int a[N];
	int front;
	int rear;
	
}Qnode; 



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


	
void getQQ(string a){
	
	int x;
	Qnode A;
	init(A);
	
	for(int i=0;i<a.length();i++){
		EnQueue(A,a[i]-'0');
	}
	
	for(int i=0;A.front!=A.rear;i++){
		
		if(i%2==0){
			DeQueue(A,x);
			cout<<x;
		}else{
			DeQueue(A,x);
			EnQueue(A,x); 
		}
		
			
	}
	
}






int main(){


    string number;

    getline(cin,number);

	getQQ(number);


	return 0;
}




