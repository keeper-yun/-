
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
	
	if(elem == '#')
		return NULL;
	else{
		local T = (local)malloc(sizeof(BiTree));
		T->data = elem;
		T->lchild = init();
		T->rchild = init();
		
		return T;
	}	
		
}



local remove_degree1(local root){
	if (root == NULL) return NULL;
    
    if(root->lchild!=NULL && root->rchild==NULL){
    	local tem = root->lchild;
    	free(root);
    	return remove_degree1(tem);
	}
	
	  if(root->rchild!=NULL && root->lchild==NULL){
    	local tem = root->rchild;
    	free(root);
    	return remove_degree1(tem);
	}

	root->lchild = remove_degree1(root->lchild);
	root->rchild = remove_degree1(root->rchild);
	
	return root;
}



void preorder(local root){
	if(root!=NULL){
		cout<<root->data;
		preorder(root->lchild);
		preorder(root->rchild);
	}
}



int main(){

	local bt1 = init();
	
	bt1 = remove_degree1(bt1);
	
	preorder(bt1);
	
	cout<<endl;
	
	return 0;
}


