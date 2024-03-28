
//¿®∫≈≈‰∂‘ 

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


void getelem(SeqStack &L){
	if(!empty(L)){
		char x = *L.top;
		cout<<"’ª∂•‘™Àÿ «:"<<x<<endl;
	}else{
		cout<<"’ª∂•Œ™ø’£¨√ª”–‘™Àÿ!"<<endl;
	}
	
}



int push(SeqStack &L,char x){
	
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
		cout<<"’ª∂•Œ™ø’£¨√ª”–‘™Àÿ!"<<endl;
		return true;
	}
	
	char x = *L.top;
	L.top--;
	cout << "…æ≥˝µƒ’ª∂•‘™Àÿ «:"<<x<<endl;
	return true;
}



bool judge(string a/*char a[]*/,int length){
	
	SeqStack A;
	init(A);
	
	for(int i=0;i<length;i++){
		char left;
		
		if(a[i]=='(' || a[i]=='['){
			push(A,a[i]);
		}else if(a[i]==')' || a[i]==']'){
			if(empty(A))
				return false;
					
			left = *A.top;
			A.top--;
			
			if( (left == ')' && a[i] == '(') || (left == ']' && a[i] == '[') ){
				pop(A);
			}
		}
		
	}
	if(empty(A)){
		cout<<"∆•≈‰≥…π¶!"<<endl;
		return true;
	}
	else{
		cout<<"∆•≈‰ ß∞‹!"<<endl;
		return false;
	}
		
		
}



int strlength(char a[]){
	int count = 0;
	while(a[count]!='\0'){
		count++;
	}
	return count;
}



int main(){
	
//	char a[]= "(1+[1+2*7-(3+4)/7]";
//	int length = strlength();
//	judge(a,length);
	
	string s;
	getline(cin, s);
	
	int length = s.length();
	
	judge(s,length);
	
	return 0;
}





