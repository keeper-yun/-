//µÚÒ»Ìâ

#include<iostream>
#include<malloc.h>

using namespace std;

typedef int use;

typedef struct Seqstack{
	use *base;
	use *top;
}Seqstack;



void init(Seqstack &L){
	
	L.base = (use *)malloc(sizeof(use)*100);
	L.top = L.base;

}



int push(Seqstack &L,int x){
	
	if(L.top > L.base+100){
		return 0;	
	}
	
	L.top++;
	*L.top = x;
	return 1;
	
}



void write(Seqstack &L){
	int x;
	while(L.base != L.top){
		x = *L.top;
		L.top--;
		cout<<x;
		if( (L.top - L.base) > 0)
			cout<<"*";
	}
	cout<<endl;
}



int detach(int n){
	
	int i=2;
	
	if(n <= 1)
		return 0;
	
	Seqstack A;
	init(A);
	
	cout<<n<<"=";
	
	while(n!=1){
		if(n%i==0){
			push(A,i);
			n = n/i;
		}else{
			i++;
		}
	
	}
	
	write(A);
	
	return 1;
}



int main(){
	
	int n;
	
	cin>>n;
	
	detach(n);
	
	return 0;
}
