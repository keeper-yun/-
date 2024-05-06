
#include<queue>
#include<iostream>

using namespace std;

typedef char elemtype;

typedef struct biTree{
	
	struct biTree * lchild;
	elemtype data;
	struct biTree * rchild;
	
}biTree,*local;



local init() {
	
	elemtype elem;
	cin >> elem;
	if(elem == '#'){
		return NULL;
	}else {
		local T = (biTree *)malloc(sizeof(local));
		T->data = elem;
		T->lchild = init();
		T->rchild = init();
		
		return T;
	}
	
}


//�������� 
void preorder(local bt,int level){
	if(bt != NULL){
		cout<<bt->data<<level<<" ";
		preorder(bt->lchild,level++);
		preorder(bt->rchild,level++);
	}
}



//�������� 
void inorder(local bt,int level){
	if(bt != NULL){
		inorder(bt->lchild,level++);
		cout<<bt->data<<level<<" ";
		inorder(bt->rchild,level++);
	}
}



//�������� 
void postorder(local bt,int level){
	if(bt != NULL){
		postorder(bt->lchild,level++);
		postorder(bt->rchild,level++);
		cout<<bt->data<<level<<" ";
	}
}



//�������
void levelorder(local bt){
	if(bt==NULL) return ;
	
	queue <local> q;
	q.push(bt);
	
	while(!q.empty()){
		local node = q.front();
		q.pop();
		
		cout << node->data << " ";
		
		if(node->lchild != NULL){
			q.push(node->lchild);
		}
		
		if(node->rchild != NULL){
			q.push(node->rchild);
		}
		
	}
	
} 



//���������
int depth(local bt){
	if(bt==NULL) return 0;
	
	int left = depth(bt->lchild);
	int right = depth(bt->rchild);
	
	return max(left,right)+1;
} 



//��Ϊ 0 �Ľ����
int degree0(local bt){
	if(bt==NULL) return 0;
	
	if(bt->lchild==NULL && bt->rchild==NULL) return 1;
	
	return degree0(bt->lchild) + degree0(bt->rchild);
}



//��Ϊ 1 �Ľ����
int degree1(local bt){
	if(bt==NULL) return 0;
	
	if( (bt->lchild==NULL && bt->rchild!=NULL) || (bt->lchild!=NULL && bt->rchild==NULL) )
		return 1 + degree1(bt->lchild) + degree1(bt->rchild);
	
	return degree1(bt->lchild) + degree1(bt->rchild);
	
}



//��Ϊ 2 �Ľ����
int degree2(local bt){
	if(bt==NULL) return 0;
	
	if(bt->lchild && bt->rchild)
		return 1 + degree2(bt->lchild) + degree2(bt->rchild);
	else
		return  degree2(bt->lchild) + degree2(bt->rchild);
	
}


int main() {
	
	local bt1 = init();
	
	//AB#CD##E##F#GH### 
	
	//preorder(bt1,1); //�������   
	
	//inorder(bt1,1);	//�������
	 
	//postorder(bt1,1);	//�������
	
	//levelorder(bt1);	//�������
	
	//cout<<depth(bt1);	//���������
	
	//cout<<degree0(bt1);	//��Ϊ 0 �Ľ����
	 
	//cout<<degree1(bt1);		//��Ϊ 1 �Ľ����
	 
	//cout<<degree2(bt1);	//��Ϊ 2 �Ľ����
	
	cout<<endl;
	
	return 0;
}





