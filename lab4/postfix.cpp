
#include<iostream>
#include<string>
#include<malloc.h>
using namespace std;

#define N 100
#define add 10

typedef struct {
	char *base;
	char *top;
	int stacksize;
}SeqStack; 



void init(SeqStack &L){
	L.base = (char *)malloc(sizeof(int)*N);	
	L.top = L.base;
	L.stacksize = N;
}



bool empty(SeqStack &L){
	
	if(L.base == L.top){
		return true;
	} 
	return false;
}


int getelem(SeqStack &L){
	if(!empty(L)){
		int x = *L.top;
		return x;
	}else{
		cout<<"ջ��Ϊ�գ�û��Ԫ��!"<<endl;
	}
	return 0; 
}



int push(SeqStack &L,int x){
	
	if(L.top-L.base > N){
		L.base = (char *)realloc(L.base,(sizeof(int)*(L.stacksize+add)));
		L.top = L.base + L.stacksize;
		L.stacksize +=add;
	}
	
	L.top++;
	*L.top = x;
}



bool pop(SeqStack &L){
	
	if(empty(L)){
		cout<<"ջ��Ϊ�գ�û��Ԫ��!"<<endl;
		return true;
	}
	
	int x = *L.top;
	L.top--;
	return true;
}



void postfix(string a,int length){
	
	SeqStack A;
	init(A);
	
	for(int i=0;i<length;i++){
		if(isdigit(a[i])){	//isdigit(a[i])��C++�ķ��� 
			int num = a[i] - '0';
			push(A,num);	
		}else if(a[i]=='+' || a[i]=='-' ||a[i]=='*' ||a[i]=='/'){
			
			int num1 = getelem(A);
			pop(A);
			
			int num2 = getelem(A);
			pop(A);
			
			switch(a[i]){
				case '+':
					push(A,num1+num2);
					break;
				case '-':
					push(A,num2-num1);
					break;
				case '*':
					push(A,num1*num2);
					break;
				case '/':
					push(A,num2/num1);
					break;
			}
		}
	}
	
	int n = getelem(A);
	cout<<"��������:"<<n<<endl;
	
}



int main(){
	
//	1341+*+5-
	string s;
	getline(cin, s);
	
	int length = s.length();
	
	postfix(s,length);
	
	
	return 0;
}

