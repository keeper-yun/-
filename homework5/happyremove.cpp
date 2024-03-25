//第二题

#include<iostream>
#include<malloc.h>

using namespace std;

typedef char use;

typedef struct Seqstack{
 	
 	use *base;
 	use *top;

}Seqstack;
 
 

void init(Seqstack &L){
	
	L.base = (use *)malloc(sizeof(use)*100);
	L.top = L.base;

}



bool empty(Seqstack &L){
	
	if(L.base == L.top){
		return true;
	} 
	return false;
}


 
int push(Seqstack &L,use x){
	
	if(L.top > L.base+100){
		return 0;
	}
	
	L.top++;
	*L.top = x;
	return 1;
}



bool pop(Seqstack &L){
	
	if(empty(L)){
		cout<<"栈顶为空，没有元素!"<<endl;
		return true;
	}
	
	use x = *L.top;
	L.top--;
	//cout << "删除的栈顶元素是:"<<x<<endl;
	return true;
}



use getelem(Seqstack &L){
	if(empty(L))
		return 0;
	use x = *L.top;
	return x;
}



void stringdeal(string s){
	
	int strlength = s.length();
	
	Seqstack A;
	init(A);
	
	for(int i=0;i<strlength;i++){
		use num = getelem(A);
		if(num == s[i]){
			pop(A);
		}else{
			push(A,s[i]);
		}
	}
	
	while(A.base < A.top){
		A.base++;
		cout<<*A.base;
	}
	cout<<endl;
	
}


int main(){
	
	string s;
	
	cin >> s;
	
	stringdeal(s);
	
	return 0;
} 
