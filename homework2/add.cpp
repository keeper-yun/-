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

void OrderedInsert(SeqList &L,int x){
	if (L.length >= 100) {
        cout << "Error!" << endl;
        return;
    }
    
    
	if(x<=L.a[0]){
		for(int i=L.length;i>=0;i--){
			L.a[i+1]=L.a[i];
		}
		L.a[0]=x;
		L.length++;
	}else if(x>=L.a[L.length-1]){
		L.a[L.length]=x;
		L.length++;
	}else {
		for(int i=0;i<L.length;i++){
			if(x>=L.a[i]&&x<=L.a[i+1]){
				for(int j=L.length-1;j>=i+1;j--){
					L.a[j+1]=L.a[j];
				}
				L.a[i+1]=x;
				L.length++;
				break;
			}
		}
	
	}
	
	
}

void write(SeqList &L){
	for(int i=0;i<L.length;i++){
		cout<<L.a[i]<<" ";
	}
	cout<<endl;
}

int main(void){
	SeqList A;
	int x;
	int a[10]={1,3,5,7,9,11,13,15,17,19};
	
	init(A,a,10);
	
	cin>>x;
	OrderedInsert(A,x);
	
	write(A);
	return 0;
}
