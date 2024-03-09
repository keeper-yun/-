#include <iostream>
using namespace std;

#define N 100
typedef int array;

typedef struct SeqList {
    array a[N];
    int length;
} SeqList;

// ��ʼ��
void init(SeqList &L,int a[],int len) {
	L.length=len;
	for(int i=0;i<L.length;i++){
		L.a[i]=a[i];
	}
}

//�п�
void ifnothing(SeqList &L){
	if(L.length==0)
		cout<<"����һ���ձ�!\n";
	else
		cout<<"������е㶫��!\n";	  
} 

//��� 
void clean(SeqList &L){
	L.length=0;
}

//����Ԫ�� 
bool insert(SeqList &L,int i,array x){
    if(i<1 || i>L.length+1 || L.length>=N)
        return false;
    for(int j=L.length-1;j>=i-1;j--){
        L.a[j+1]=L.a[j];
    }
    L.a[i-1]=x;
    L.length++;
    return true;
}

//ɾ��Ԫ�� 
bool remove(SeqList &L,int i,array &x){
    if(i<1 || i>L.length)
        return false;
    x=L.a[i-1];
    for(int k=i-1;k<L.length;k++){
        L.a[k]=L.a[k+1];
    }
    L.length--;
    return true;
}

//�ϲ���
void merge(SeqList &L1,SeqList &L2,SeqList &L3){
	int i=0,j=0,k=0;
	
	while(i<L1.length&&j<L2.length){
		if(L1.a[i]<L2.a[j]){
			L3.a[k]=L1.a[i];
			i++;
		}else if(L1.a[i]>L2.a[j]){
			L3.a[k]=L2.a[j];
			j++;
		}else{
			L3.a[k]=L2.a[j];
			i++;
			j++;
		}
		k++;
	}
	
	while(i<L1.length){
		L3.a[k]=L1.a[j];
		k++;
		j++;
	}
	
	while(j<L2.length){
		L3.a[k]=L2.a[j];
		k++;
		j++;
	}
	
	L3.length=k;
}


// ��ӡ 
void traverse(SeqList &L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.a[i] << " ";
    }
}

int main(void) {
    SeqList A,B,F;
    array x=0;
    array a[5]={1,2,3,4,5};
    array b[5]={7,8,9,10,11};
    init(A,a,5);	//��ʼ��һ��
    ifnothing(A); 	//�п�
    
	clean(A); 		//��� 
	ifnothing(A);	//�п�(�ڶ���)
	
	init(A,a,5);	//��ʼ��(�ڶ���)
	insert(A,6,6);	//��5֮�����Ԫ��{1,2,3,4,5,6}	 
    remove(A,2,x);	//ɾȥ2Ԫ��{1,3,4,5,6}
	
	init(B,b,5);	//��ʼ��B 
	merge(A,B,F);
	 
    cout<<endl<<x<<endl;	//��ӡɾȥ��Ԫ�� 
	traverse(F);	//��ӡ����Ԫ�� 

	cout<<endl;
    system("pause");
	return 0;
}





