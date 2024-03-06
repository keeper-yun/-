#include<iostream>
using namespace std;

typedef struct SeqList{
	int a[100];
	int length;
}SeqList;

void init(SeqList &L,int a[],int len){
	L.length=len;
	for(int i=0;i<L.length;i++){
		L.a[i]=a[i];
	}
}

bool remove(SeqList &L,int a,int b){
	if(a<1||a>L.length||b<=0||a+b-1>L.length)
        return false;
	for(int i=a-1;i<L.length-b;i++){
		L.a[i]=L.a[i+b];
	}
	L.length=L.length-b;
	return true;
}

void write(SeqList &L){
	for(int i=0;i<L.length;i++){
		cout<<L.a[i]<<" ";
	}
	cout<<endl;
}

int main(void){
	SeqList A;
	int x,y;
	int a[10]={10,9,8,7,6,5,4,3,2,1};
	
	init(A,a,10);
	
	cin>>x;
	cin>>y;
	if(remove(A,x,y)){
		write(A);
	}else{
		cout<<"error"<<endl;
	}
	

	return 0;
}
