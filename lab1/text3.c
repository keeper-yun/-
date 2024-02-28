#include <stdio.h>
#include <stdlib.h>

struct node
{
	int bcode;
	struct node* next;
};

void convert(int x){
    struct node * head=NULL,*p;

    while (x>0){
        int r = x % 2;
        x=x/2;
        p=(struct node *)malloc(sizeof(struct node));
        p->bcode = r;
        p->next = head;
        head = p;
    }

    p=head;
    while (p!=NULL)
    {
        printf("%d",p->bcode);
        p = p->next;
    }
    
}

int main(){
	int i;
	printf("请输入一个整数\n");
	scanf("%d",&i);
	printf("其二进制形式为：\n");
	convert(i);
    printf("\n");
    return 0;
}


