#include<iostream>

using namespace std;

typedef char elemtype;

typedef struct BiTree{
	
	struct BiTree *lchild;
	elemtype data;
	struct BiTree *rchild;
	
}BiTree,*local;



local init(){
	
	elemtype elem;
	cin>>elem;
	
	if(elem=='#') return NULL;
	
	else{
		local T = (local)malloc(sizeof(BiTree));
		T->data = elem;
		T->lchild = init();
		T->rchild = init();
		
		return T;
	}
	
}



//度为 2 的结点数
int degree2(local bt){
	if(bt==NULL) return 0;
	
	if(bt->lchild && bt->rchild)
		return 1 + degree2(bt->lchild) + degree2(bt->rchild);
	else
		return  degree2(bt->lchild) + degree2(bt->rchild);
	
}



int main(){
	
	local bt1 = init();
	
	cout<<degree2(bt1);
	
	cout<<endl;
	
	return 0;
}
